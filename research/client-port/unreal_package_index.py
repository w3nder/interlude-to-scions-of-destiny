"""Read-only Unreal 2 package name/import/export index for asset verification.
Supports unencrypted packages and Lineage2Ver111/121 XOR containers.
Does not deserialize or execute objects.
"""
import struct
from collections import Counter
from pathlib import Path
class Package:
 def __init__(self,path):
  self.path=Path(path);self.f=self.path.open('rb');header=self.f.read(30);self.offset=0;key=0
  if header.startswith('Lineage2Ver'.encode('utf-16le')):
   version=header[:28].decode('utf-16le');self.offset=28
   if version=='Lineage2Ver111':key=0xac
   elif version=='Lineage2Ver121':key=sum(self.path.name.lower().encode())&255
   else:raise ValueError('Unsupported package encryption '+version)
  self.translate=bytes(i^key for i in range(256));header=self.read(0,64)
  if header[:4]!=bytes.fromhex('c1832a9e'):raise ValueError('Bad Unreal magic '+str(path))
  self.version,self.license=struct.unpack_from('<HH',header,4)
  nc,no,ec,eo,ic,io=struct.unpack_from('<6I',header,12)
  if max(nc,ec,ic)>1000000:raise ValueError('Unbounded table')
  self.names=[];self.pos=no
  for _ in range(nc):
   n=self.compact()
   if abs(n)>10000:raise ValueError('Unbounded name')
   data=self.take(abs(n)*(2 if n<0 else 1))
   self.names.append(data.decode('utf-16le' if n<0 else 'latin1').rstrip('\0'));self.take(4)
  self.imports=[];self.pos=io
  for _ in range(ic):
   cp=self.compact();cl=self.compact();outer=self.i32();name=self.compact()
   self.imports.append(dict(class_package=self.name(cp),class_name=self.name(cl),outer=outer,name=self.name(name)))
  self.exports=[];self.pos=eo
  for _ in range(ec):
   cl=self.compact();super_=self.compact();outer=self.i32();name=self.compact();flags=self.take(4);size=self.compact();off=self.compact() if size else 0
   self.exports.append(dict(class_index=cl,outer=outer,name=self.name(name),size=size,offset=off))
  self.objects={self.object_path(i+1).casefold() for i in range(ec)}
  self.leaves=Counter(x.rsplit('.',1)[-1] for x in self.objects)
  self.dependencies={r['name'] for r in self.imports if not r['outer'] and r['class_name']=='Package'}
  self.f.close()
 def read(self,at,n):
  self.f.seek(self.offset+at);v=self.f.read(n)
  if len(v)!=n:raise ValueError('Truncated package')
  return v.translate(self.translate)
 def take(self,n):
  v=self.read(self.pos,n);self.pos+=n;return v
 def i32(self):return struct.unpack('<i',self.take(4))[0]
 def compact(self):
  b=self.take(1)[0];neg=b&128;v=b&63;more=b&64;shift=6
  for j in range(4):
   if not more:return -v if neg else v
   b=self.take(1)[0];v|=(b&(31 if j==3 else 127))<<shift;more=b&128;shift+=7
  if more:raise ValueError('Compact overflow')
  return -v if neg else v
 def name(self,i):
  if not 0<=i<len(self.names):raise ValueError('Bad name index')
  return self.names[i]
 def object_path(self,i,seen=None):
  if not i:return ''
  seen=set() if seen is None else seen
  if i in seen:raise ValueError('Outer cycle')
  seen.add(i);r=self.exports[i-1] if i>0 else self.imports[-i-1]
  prefix=self.object_path(r['outer'],seen);return prefix+'.'+r['name'] if prefix else r['name']

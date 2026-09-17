"""Bounded reader for the UE2 token subset in the pinned inventory function.

Serialized object/name references use compact integers but occupy four bytes in
VM bytecode. Offsets below distinguish those two address spaces. Unknown tokens
are rejected. Format reference: acmi/L2unreal token definitions (MIT).
"""
import struct
class Reader:
 def __init__(self,b):self.b=b;self.p=0
 def num(self,n):
  if self.p+n>len(self.b):raise ValueError('truncated')
  v=int.from_bytes(self.b[self.p:self.p+n],'little');self.p+=n;return v
 def compact(self):
  b=self.num(1);sign=b&128;more=b&64;v=b&63;s=6
  for i in range(4):
   if not more:return -v if sign else v
   b=self.num(1);v|=(b&127)<<s;s+=7;more=b&128
  if more:raise ValueError('compact overflow')
  return -v if sign else v
class Parser(Reader):
 def __init__(self,b):super().__init__(b);self.v=0;self.nodes=[]
 def n(self,n):self.v+=n;return self.num(n)
 def ref(self):v=self.compact();self.v+=4;return v
 def token(self):
  t={'p':self.p,'v':self.v,'children':[]};op=self.n(1);t['op']=op;self.nodes.append(t)
  def child():v=self.token();t['children'].append(v);return v
  def jump():t['jump_p']=self.p;t['jump']=self.n(2)
  if op in [0,1,2,0x20,0x21,0x29]:t['ref']=self.ref()
  elif op in [0x04,0x0d,0x0e,0x2d,0x37]:child()
  elif op==5:t['width']=self.n(1);child()
  elif op in [6,0x18]:jump()
  elif op==7:jump();child()
  elif op==0xa:
   jump()
   if t['jump']!=65535:child()
  elif op in [8,0xb,0x16,0x17,0x25,0x26,0x27,0x28,0x2a,0x30,0x31]:pass
  elif op in [0xf,0x10,0x14,0x1a]:child();child()
  elif op==0x11:
   for _ in range(4):child()
  elif op in [0x12,0x19]:
   child();t['skip_p']=self.p;t['skip']=self.n(2);t['size']=self.n(1);child()
  elif op in [0x13,0x2e,0x36]:t['ref']=self.ref();child()
  elif op in [0x32,0x33]:t['ref']=self.ref();child();child()
  elif op in [0x1b,0x1c,0x38] or op>=0x60:
   if op<0x60:t['ref']=self.ref()
   elif op<0x70:t['native']=((op-0x60)<<8)|self.n(1)
   else:t['native']=op
   while child()['op']!=0x16:pass
  elif op in [0x1d,0x1e]:t['value']=self.n(4)
  elif op in [0x24,0x2c]:t['value']=self.n(1)
  elif op==0x1f:
   begin=self.p
   while self.n(1):pass
   t['value']=self.b[begin:self.p-1].decode('latin1')
  elif op in [0x22,0x23]:
   for _ in range(3):self.n(4)
  else:raise ValueError((hex(op),self.p,self.v))
  t['end']=self.p;t['vend']=self.v;return t
 def script(self,size):
  tops=[]
  while self.v<size:tops.append(self.token())
  assert self.v==size,(self.v,size)
  return tops

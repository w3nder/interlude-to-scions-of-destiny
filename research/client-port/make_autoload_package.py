"""Create a reversible, hash-gated diagnostic Interlude system."""
from pathlib import Path
import hashlib,json,re,shutil,struct
import pefile
from concurrent.futures import ThreadPoolExecutor
import sys
from ini_codec import decode,encode
ROOT=Path(__file__).resolve().parent
SOURCE=Path('/Users/wenderteixeira/Desktop/C6_System_Win10Supported')
EXPECTED='790d9068796714389d82a400d14d26dcb9e6ecdfc6c2b5eba92ebd1a441b10ee'
def align(n,a): return (n+a-1)//a*a
def patch(raw):
    if hashlib.sha256(raw).hexdigest()!=EXPECTED: raise ValueError('Unsupported executable hash')
    pe=pefile.PE(data=raw); data=bytearray(raw); fa=pe.OPTIONAL_HEADER.FileAlignment; sa=pe.OPTIONAL_HEADER.SectionAlignment
    rva=align(max(s.VirtualAddress+max(s.Misc_VirtualSize,s.SizeOfRawData) for s in pe.sections),sa)
    pos=align(len(raw),fa); section=bytearray(64)
    def add(blob,alignment=4):
        section.extend(bytes((-len(section))%alignment)); off=len(section); section.extend(blob); return rva+off
    dll=add(b'L2KProtocolCore.dll\0'); name=add(b'\0\0l2k_bootstrap\0',2)
    ilt=add(struct.pack('<II',name,0)); iat=add(struct.pack('<II',name,0))
    descriptors=b''.join(e.struct.__pack__() for e in pe.DIRECTORY_ENTRY_IMPORT)
    imports=add(descriptors+struct.pack('<IIIII',ilt,0,0,dll,iat)+bytes(20))
    # push flags/registers, calculate actual base, call import, restore, jump OEP.
    stub=b'\x9c\x60\xe8\0\0\0\0\x5b\x81\xeb'+struct.pack('<I',rva+7)
    stub+=b'\xff\x93'+struct.pack('<I',iat)+b'\x61\x9d'
    stub+=b'\xe9'+struct.pack('<i',pe.OPTIONAL_HEADER.AddressOfEntryPoint-(rva+len(stub)+5))
    section[:len(stub)]=stub
    sh=pe.sections[-1].get_file_offset()+40
    if sh+40>pe.OPTIONAL_HEADER.SizeOfHeaders: raise ValueError('No section header space')
    size=align(len(section),fa)
    data[sh:sh+40]=struct.pack('<8sIIIIIIHHI',b'.l2k\0\0\0\0',len(section),rva,size,pos,0,0,0,0,0xe0000060)
    def setfield(obj,field,value,fmt='<I'): struct.pack_into(fmt,data,obj.get_field_absolute_offset(field),value)
    setfield(pe.FILE_HEADER,'NumberOfSections',len(pe.sections)+1,'<H')
    setfield(pe.OPTIONAL_HEADER,'AddressOfEntryPoint',rva)
    setfield(pe.OPTIONAL_HEADER,'SizeOfImage',align(rva+len(section),sa))
    setfield(pe.OPTIONAL_HEADER,'SizeOfCode',pe.OPTIONAL_HEADER.SizeOfCode+size)
    setfield(pe.OPTIONAL_HEADER,'CheckSum',0)
    for idx,va,length in [(1,imports,len(descriptors)+40),(11,0,0)]:
        entry=pe.OPTIONAL_HEADER.DATA_DIRECTORY[idx];setfield(entry,'VirtualAddress',va);setfield(entry,'Size',length)
    data.extend(bytes(pos-len(data))); data.extend(section); data.extend(bytes(size-len(section)))
    checksum=pefile.PE(data=data).generate_checksum();setfield(pe.OPTIONAL_HEADER,'CheckSum',checksum)
    return bytes(data)

def copy_bytes(src,dst):
    Path(dst).write_bytes(Path(src).read_bytes())
    return str(dst)

def main():
    dest=ROOT/'dist/L2Killer-Interlude-LoginTest'; target=dest/'system'
    if dest.exists() and '--resume-build' not in sys.argv: raise SystemExit('Output already exists; use --resume-build only for an incomplete build')
    if (dest/'manifest.json').exists(): raise SystemExit('Completed package already exists')
    original=(SOURCE/'l2.exe').read_bytes(); patched=patch(original)
    sourceini=decode((SOURCE/'l2.ini').read_bytes())
    newini,count=re.subn(rb'(?im)^ServerAddr=[^\r\n]*',b'ServerAddr=server.l2killer.org',sourceini)
    if count!=1: raise ValueError('Expected exactly one ServerAddr')
    encoded=encode(newini)
    assert decode(encoded)==newini
    target.mkdir(parents=True,exist_ok=True)
    files=list(SOURCE.rglob('*'))
    for f in files:
        if f.is_dir():(target/f.relative_to(SOURCE)).mkdir(exist_ok=True)
    def copy_one(f):
        output=target/f.relative_to(SOURCE)
        copy_bytes(f,output)
    with ThreadPoolExecutor(max_workers=8) as pool:
        list(pool.map(copy_one,(f for f in files if f.is_file())))
    copy_bytes(target/'l2.exe',target/'l2.exe.before-l2k');copy_bytes(target/'l2.ini',target/'l2.ini.before-l2k')
    (target/'l2.exe').write_bytes(patched);(target/'l2.ini').write_bytes(encoded)
    copy_bytes(ROOT/'build/L2KProtocolCore.dll',target/'L2KProtocolCore.dll')
    (dest/'LEIA-ME.txt').write_text('TESTE REAL DE LOGIN C4 NO CLIENTE INTERLUDE\n\nAbra system/l2.exe pelo Wine. A DLL carrega e instala os hooks automaticamente.\nUse sua conta na interface do jogo. O marco desta etapa e a lista de servidores.\nO transporte de jogo e os pacotes de personagem ainda nao foram ligados; nao teste entrar no mundo nesta versao.\nLog: system/L2KProtocol.log. Procure hooks=login_active, Init accepted, LoginOk accepted e ServerList received.\nO log nao grava conta, senha nem chaves. Falhas de checksum ou pacotes desconhecidos fecham a conexao.\nServerAddr=server.l2killer.org; Port=7777 preservado. A rotina original conecta ao login em 2106.\nBase: C6_System_Win10Supported, com a mesma engine e executavel validados de system-1.\nPara desfazer, restaure o backup completo system.before-l2k-* criado na instalacao.\nTeste emulado concluido; login real depende da validacao no Wine.\n')
    files=['l2.exe','l2.ini','L2KProtocolCore.dll']
    manifest={'status':'experimental login hooks; game hooks pending','source':str(SOURCE),'original_exe_sha256':EXPECTED,'server':'server.l2killer.org','sha256':{f:hashlib.sha256((target/f).read_bytes()).hexdigest() for f in files}}
    (dest/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    archive=shutil.make_archive(str(dest),'zip',dest.parent,dest.name);print(archive)
if __name__=='__main__': main()

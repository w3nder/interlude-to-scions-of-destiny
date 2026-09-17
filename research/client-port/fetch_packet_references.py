import concurrent.futures,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parent
DEST=ROOT/'references/interlude';DEST.mkdir(parents=True,exist_ok=True)
NAMES=['TargetSelected','TargetUnselected','MyTargetSelected','DoorInfo','FlyToLocation','SpecialCamera','EtcStatusUpdate','SkillList','GMViewSkillInfo','ExFishingStart','ExFishingStartCombat','ExFishingHpRegen','ExAskJoinMPCC','PetStatusUpdate','ExEnchantSkillList','ExEnchantSkillInfo','NpcInfo','ItemList','InventoryUpdate','PetInventoryUpdate','WareHouseWithdrawalList','WareHouseDepositList','ShortCutInit','ShortCutRegister','PledgeStatusChanged','Ride','RequestJoinPledge','RequestJoinPartyRoom','RequestMultiSellChoose','RequestPledgePower','MultiSellList','ExMultiPartyCommandChannelInfo','CharInfo','UserInfo','CharSelectInfo','CharSelected','PetInfo','SystemMessage','ConfirmDlg','QuestList','GMViewPledgeInfo','GMViewItemList','GMViewWarehouseWithdrawList','WarehouseDepositList','WarehouseWithdrawalList','AskJoinPledge','ManagePledgePower']
BASE='https://raw.githubusercontent.com/VytautasBoznis/l2.skilas.lt/master/aCis_gameserver/java/net/sf/l2j/gameserver/network/serverpackets/'
def fetch(name):
 p=DEST/(name+'.java')
 if not p.exists():
  r=subprocess.run(['curl','-fsSL','--connect-timeout','10','--max-time','30',BASE+name+'.java','-o',str(p)],capture_output=True,text=True)
  if r.returncode:return name,r.stderr.strip()
 return name,'saved'
if __name__=='__main__':
 with concurrent.futures.ThreadPoolExecutor(max_workers=5) as pool:
  for name,result in pool.map(fetch,NAMES):print(name,result,flush=True)

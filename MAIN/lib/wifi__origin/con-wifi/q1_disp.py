from func import *
def _disp():
	# displays available wifi hotspot(s)
	system('nmcli d wifi list')
	print ''

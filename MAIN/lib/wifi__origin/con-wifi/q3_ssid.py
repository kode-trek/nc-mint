from func import *
def _ssid():
	#	makes a list of all SSID(s)
	v0 = '.' + str(int(time()))
	system('nmcli -t -f ssid dev wifi > ' + v0)
	fh = open(v0); v1 = fh.readlines(); fh.close()
	system('rm ' + v0)
	v0 = []
	for i in v1:	v0.append(i[:-1])
	# displays the list for the user to pick one by its number.
	c = 1
	for i in v0:
		print str(c) + ': ' + i
		c += 1
	print ''
	flg = 1
	while(flg):
		ssid = raw_input('SSID[#]: ')
		try:
			if int(ssid) not in range(1, len(v0)+1):
				print '[FAILED] take an item from the list!'
			else:
				flg = 0
				# collects another parameter for the <lst>
				lst.append(v0[int(ssid)-1])
		except:	print '[FAILED] invalid entry!'

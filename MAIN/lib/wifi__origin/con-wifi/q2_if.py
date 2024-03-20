from func import *
def _if():
	#	elicits wifi-interface(wifi-if)
	v0 = '.' + str(int(time()))
	system('ifconfig > ' + v0)
	fh = open(v0); v1 = fh.read(); fh.close()
	system('rm ' + v0)
	v1 = v1.split('\n\n')
	# we expect a device-name like: wlp2s0
	for i in range(len(v1)):
		if (len(v1[i]) != 0) and v1[i][0] == 'w':
			# collects another parameter for the <lst>
			lst.append(v1[i].split(' ')[0])

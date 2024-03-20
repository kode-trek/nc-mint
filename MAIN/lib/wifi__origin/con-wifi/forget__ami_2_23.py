# elicits list of already built connections by UUID:
v0 = '.' + str(int(time()))
system('nmcli -t -f UUID con show > ' + v0)

# elicits list of already built connections by Name:
v0 = '.' + str(int(time()))
system('nmcli -t -f Name con show > ' + v0)

for i in v1:	name.append(i[:-1])
try:	# user may Interrupt (Ctrl + C) the procedure at any time.
	# displays list of already built connections by Name:
	c = 1
	for i in name:
		print str(c) + ': ' + i
		c += 1
	print ''
	flg = 1
	while(flg):
		# user picks an item by number to remove from the list:
		item = raw_input('SSID [#|all]: ')
		if item == 'all':
			# <all> and cleans the entire list:
			for i in uuid:	system('nmcli con delete uuid ' + i)
			exit()
		try:
			if int(item) not in range(1, len(name) + 1):
				print '[FAILED] pick an item from the list!'
			else:
				flg = 0
				system('nmcli con delete uuid ' + uuid[int(item)-1])
		except:		print '[FAILED] invalid entry!'
except:
	print ''
	exit()

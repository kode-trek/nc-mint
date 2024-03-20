from func import *
def _pass():
	_pass = getpass('password for [' + lst[1] + ']: ')
	# must be at least 8 characters.
	while (len(_pass) < 8):
		print 'password need to be at least 8 characters.'
		_pass = getpass('password for [' + lst[1] + ']: ')
	# collects another parameter for the <lst>
	lst.append(_pass)

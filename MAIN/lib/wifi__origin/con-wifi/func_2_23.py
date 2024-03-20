from os import system, listdir, mkdir, chdir, rename, remove, stat, getuid
from os.path import isdir, basename, dirname, exists
from sys import argv, exit
from time import time
from random import random
from shutil import copyfile, move, rmtree
from urlparse import urlparse
from getpass import getuser
def uri(arg1):
	p = urlparse(arg1).path
	d = dirname(p)
	b = basename(p)
	# (ext)ension
	if '.' in b:	ext = '.' + b.split('.')[-1]
	else:					ext = '.DAT'
	# file-name (excluding extension)
	fn = b[:-len(ext)]
	return (p, d, b, fn, ext)

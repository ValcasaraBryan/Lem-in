#!/usr/bin/python3
#coding : utf-8
#Chaton le 18/02 pour Chaton

from itertools import chain
import sys

src,dst=0,0
useless = []
usefull = []



def usage():
	print("""Usage : 
		     python3 doublons.py srcfile dstfile""")
	sys.exit(-1)



if(len(sys.argv)!=3):
	usage()
try:
	src,dst = sys.argv[len(sys.argv)-2],sys.argv[len(sys.argv)-1]
	src = open(src,'r')
	dst = open(dst,'w')
except:
	usage()

for line in src.readlines():
	if not "-" in line:
		useless.append(line.rstrip())
	else:
		usefull.append(line.rstrip())
usefull = set(usefull)
tmp = set(list(chain(*[[str(c.split("-")[1])+"-"+
	                        str(c.split("-")[0])] for c in list(usefull)])))
usefull -= tmp
usefull = useless+list(sorted(usefull))
for line in usefull:
	dst.write("%s\n" % line)
src.close()
dst.close()
print("Done")
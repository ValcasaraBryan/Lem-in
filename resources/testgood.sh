#!/bin/sh
make
# for f in ./tests/good_maps/*;
# do 
# 	echo "$f"; 
# 	valgrind ./lem-in < $f 2>&1 | grep --color=always "lost" 
# done
for f in ./tests/good_maps/*;
do 
	echo "$f"; 
	./lem-in < $f
done

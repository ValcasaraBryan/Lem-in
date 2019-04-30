#!/bin/sh
make
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
BASE=$(tput sgr0)
BAD_TESTS=tests/bad_tests/*

printf ">> LEAK MANAGEMENT\n"
WHAT="lost"
for f in $BAD_TESTS
	do
		printf "\n>> testing ${f##*/}:\n"
		WHERE="$(valgrind --tool=memcheck --leak-check=full ./lem-in 2>&1 < $f | grep $WHAT)"
		res=$(echo "$WHERE" | grep -E 'directly|definitely' | cut -c 14-)
		echo "${res}"
	done

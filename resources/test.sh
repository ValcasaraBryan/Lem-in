# for f in ./tests/_maps/*;
# do
# 	echo "$f";
# 	./lem-in < $f
# done

for f in ./tests/bad_tests/*;
do
	echo "$f";
	./lem-in < $f
done

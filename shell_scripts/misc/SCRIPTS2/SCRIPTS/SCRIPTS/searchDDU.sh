grep "DDU" DDUFILE > f1
#cat f1
tr " " "\n" < f1 > f2
#cat f2
grep "DDU" f2 > f3
cat f3

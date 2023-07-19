# 5 4 3 2 1
# 4 3 2 1
# 3 2 1
# 2 1
# 1


for ((i=5;i>0;i--))
do
	for((j=i;j>0;j--))
	do
	echo -n  "$j "
	done
	echo ""
done	

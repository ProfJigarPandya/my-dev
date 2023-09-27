for i in {1..10}
do
	echo "drop user usr$i cascade;"
done;
echo "commit;"
echo "exit;"

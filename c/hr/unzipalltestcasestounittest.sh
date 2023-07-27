for handsOn in {1..11};
do
	#cd handson$handsOn
	for chn in `ls handson$handsOn`;
	do
		if [ "$chn" == "Aims.txt" ];
		then
			continue
		fi
		location="handson$handsOn/$chn"
		#echo $location
		unzip $location/*.zip -d $location
	done
	#cd ..
done

for fn in `ls inputFolders/.`; 
do 
	#any folder to exclude add entry here -o means logical or condition
	if [ "$fn" == "LectureTakenDetails_DAA_2020_21" -o "$fn" == "JMP-O.pdf" -o "$fn" == "rename.sh" -o "$fn" == "graph" -o "$fn" == "-" ];
	then
		continue
	fi
	nfn=`echo $fn | sed  's/^\([[:alnum:]]*\)_\(.*\)/\1/g'`
	mkdir outputFolders/$nfn
done;



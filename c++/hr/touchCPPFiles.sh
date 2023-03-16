
for aimfile in `find . -name "Aims.txt"`; 
do 
	handsonNo=`echo $aimfile| cut -d '/' -f 2`
	challengeNo=1
	for aim in `tail -n +5 $aimfile | cut -b 4- | sed -r "s/([[:space:]])([a-z]|[A-Z]|[0-9]|-|\(|\+)/\U\2/g"`;
	do
		mkdir -p "$handsonNo/challenge$challengeNo"
		touch "$handsonNo/challenge$challengeNo/$aim.cpp"
		challengeNo=`expr $challengeNo + 1`
	done
done;

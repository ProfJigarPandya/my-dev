#set source filename
#handsOnNumber=handson1
#challengeNumber=challenge1
#sourceFileName=PrimalityTest
if [ $# -ne 1 ]
then
	echo "Usage:runme.sh handsOnNumber/challengeNumber/sourceFileName(With Extension)"
	exit 1
fi

firstChar=`echo $1|cut -d "/" -f 1`
echo $firstChar
if [ $firstChar != '.' ] #i.e. run like this -> sh runme.sh handson1/challenge1/PrimalityTest.c
then
	handsOnNumber=`echo $1|cut -d "/" -f1`
	challengeNumber=`echo $1|cut -d "/" -f2`
	sourceFileNameWE=`echo $1|cut -d "/" -f3`
else # otherwise sh runme.sh ./handson1/challenge1/PrimalityTest.c
	handsOnNumber=`echo $1|cut -d "/" -f2`
	challengeNumber=`echo $1|cut -d "/" -f3`
	sourceFileNameWE=`echo $1|cut -d "/" -f4`
fi

sourceFileName=`echo $sourceFileNameWE|cut -d "." -f 1`


echo $handsOnNumber
echo $challengeNumber
echo $sourceFileName

#cleanup
rm -f ./$handsOnNumber/$challengeNumber/$sourceFileName.o
rm -rf ./$handsOnNumber/$challengeNumber/demo

#compile
g++ ./$handsOnNumber/$challengeNumber/$sourceFileName.c -o ./$handsOnNumber/$challengeNumber/$sourceFileName.o -lm

#g++ exit status is 0 upon successful compilation
if [ `echo $?` -eq 0 ]
then
	#execute and record output into demo directory
	mkdir ./$handsOnNumber/$challengeNumber/demo;
	for inFileName in `ls ./$handsOnNumber/$challengeNumber/input`; 
	do 
		outFileNameSuffix=`echo $inFileName | cut -b 6-`; 
		outFileName=output$outFileNameSuffix;
		echo "Processed Input: $inFileName Generated Output: $outFileName"; 
		./$handsOnNumber/$challengeNumber/$sourceFileName.o<./$handsOnNumber/$challengeNumber/input/$inFileName>./$handsOnNumber/$challengeNumber/demo/$outFileName;
	done;
	echo "Execution finished"
else
	echo "Compilation errors.";
fi

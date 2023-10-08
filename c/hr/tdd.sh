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
#set source filename
#handsOnNumber=handson1
#challengeNumber=challenge1
#sourceFileName=PrimalityTest

handsOnNumber=`echo $1|cut -d "/" -f1`
challengeNumber=`echo $1|cut -d "/" -f2`
sourceFileNameWE=`echo $1|cut -d "/" -f3`

if [ $# -ne 1 ];
then
	echo "Usage:validate.sh handsOnNumber/challengeNumber/sourceFileName(With Extension)"
	exit 1
fi

sourceFileName=`echo $sourceFileNameWE|cut -d "." -f 1`

echo $handsOnNumber
echo $challengeNumber
echo $sourceFileName

flag=0
for inFileName in `ls ./$handsOnNumber/$challengeNumber/input`; 
do 
	outFileNameSuffix=`echo $inFileName | cut -b 6-`; 
	outFileName=output$outFileNameSuffix;
	echo "Expected output: ./$handsOnNumber/$challengeNumber/output/$outFileName Generated Output: ./$handsOnNumber/$challengeNumber/demo/$outFileName"; 
	diff ./$handsOnNumber/$challengeNumber/output/$outFileName ./$handsOnNumber/$challengeNumber/demo/$outFileName
	if [ `echo $?` -ne 0 ];
	then
		echo "Output is not as per expectation. Test case failed."
		flag=1
		break
	else
		echo "OK. $outFileName test case passed."
	fi
done;
echo $flag
#if [ "$flag" == "0" ];
if test $flag -eq 0 ;
then
	echo "ALL TEST CASES PASSED SUCCESSFULLY. GREAT JOB."
fi

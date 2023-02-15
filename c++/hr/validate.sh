#set source filename
#handsOnNumber=handson1
#challengeNumber=challenge1
#sourceFileName=PrimalityTest

handsOnNumber=`echo $1|cut -d "/" -f1`
challengeNumber=`echo $1|cut -d "/" -f2`
sourceFileNameWE=`echo $1|cut -d "/" -f3`


if [ $# -ne 1 ]:
then
	echo "Usage:validate.sh handsOnNumber/challengeNumber/sourceFileName(With Extension)"
	exit 1
fi

sourceFileName=`echo $sourceFileNameWE|cut -d "." -f 1`

echo $handsOnNumber
echo $challengeNumber
echo $sourceFileName


for inFileName in `ls ./$handsOnNumber/$challengeNumber/input`; 
do 
	outFileNameSuffix=`echo $inFileName | cut -b 6-`; 
	outFileName=output$outFileNameSuffix;
	echo "Expected output: ./$handsOnNumber/$challengeNumber/output/$outFileName Generated Output: ./$handsOnNumber/$challengeNumber/demo/$outFileName"; 
	diff ./$handsOnNumber/$challengeNumber/output/$outFileName ./$handsOnNumber/$challengeNumber/demo/$outFileName
	if [ `echo $?` -ne 0 ]:
	then
		echo "Output is not as per expectation. Test case failed."
		break
	fi
done;

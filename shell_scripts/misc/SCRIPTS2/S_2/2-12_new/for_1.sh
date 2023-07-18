#This Script adds a header file to all the C Files containing either printf or fprintf
#!/bin/bash

for filename in *.c
do
if grep -E "(|f)printf" $filename > /dev/null 
then 
sed '1i\
#include<stdio.h>
' $filename > tempfile
cat tempfile > $filename
fi
done

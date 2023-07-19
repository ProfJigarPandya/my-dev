#!/bin/bash
# Program to display first n consonants.
# if n is 5 then output is B C D F G

disp=100

echo "Enter n"
read n
if [ $n -gt 21 ]
then
	echo "Total possible consonants are 21 as total alphabets minus 5 vowels"
	exit
fi

i=1
while [ $i -le $n ]
do

  disp=`echo "ibase=8;obase=8;$disp + 1" | bc`
  if [ `echo -e "\0$disp"` == "A" -o `echo -e "\0$disp"` == "E" -o `echo -e "\0$disp"` == "I" -o `echo -e "\0$disp"` == "O" -o `echo -e "\0$disp"` == "U" ]
  then
	continue
  else
	echo -e "\0$disp"
	i=`expr $i + 1`
  fi

done

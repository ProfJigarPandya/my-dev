#!/bin/bash

for filename in *
do
	fname=`basename $filename`
	n=`echo $fname | tr '[:upper:]' '[:lower:]'`
	if [ "$fname" != "$n" ]
	then mv $fname $n
	fi
done

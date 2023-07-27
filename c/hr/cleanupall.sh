#!/bin/bash
for i in {1..15};
do 
	echo $i
	for j in {1..15};
	do 
		echo $j
		rm -r ./handson$i/challenge$j/*.o 
		rm -r ./handson$i/challenge$j/demo
	done; 
done;


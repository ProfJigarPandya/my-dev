1.Copy files of one directory to the other after checking
#!/bin/bash

cd $1

for file in *
do
	if [ -f ../$2/$file ]
	then echo "The file $file already exists in $2"
	else	
	cp $file ../$2
	fi
done

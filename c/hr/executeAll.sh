for file in `find . -name "*.c"`; 
do 
	echo $file; 
	sh runme.sh "$file"; 
done;

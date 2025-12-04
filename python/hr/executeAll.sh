for file in `find . -name "*.py"`; 
do 
	echo $file; 
	sh runme.sh "$file"; 
done;

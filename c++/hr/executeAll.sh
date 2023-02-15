for file in `find . -name "*.cpp"`; 
do 
	echo $file; 
	sh runme.sh "$file"; 
done;

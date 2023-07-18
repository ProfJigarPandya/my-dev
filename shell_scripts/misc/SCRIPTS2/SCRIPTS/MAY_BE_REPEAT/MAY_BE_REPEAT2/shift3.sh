echo -e "\n"
set 1 2 3 4 5 6 7 8 9 0 a b c d e f g h
echo -e "first 9 arguments are :"
echo -e "$1 $2 $3 $4 $5 $6 $7 $8 $9 \n"
shift 9
echo -e "last nine arguments are :"
echo -e "$1 $2 $3 $4 $5 $6 $7 $8 $9 \n"

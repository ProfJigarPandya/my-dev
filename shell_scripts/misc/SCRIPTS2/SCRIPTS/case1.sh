echo -e " you have the following choices \n 1. who is the user \n 2. list of all files \n 3. today's date"
echo "enter your choice : "
read choice
case "$choice" in
1) whoami ;;
2) ls -l  ;;
3) date   ;;
esac

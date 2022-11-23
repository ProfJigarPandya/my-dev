echo -e 'Enter Password:\c'
read -s password
if [ -z $1 ]
then
        set 1
fi
for ((i=1;i<=$1;i++))
{
        gnome-terminal --tab -e "internalscript.sh $password"  --tab -e "/internalscript.sh $password" --tab -e "internalscript.sh $password" &
echo ''
}

exit;


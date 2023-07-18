#!/bin/bash
# Friendly script which when username and password matched to predefined values displays a welcome message or displays let's be friend message.

ufriend="friend"
pfriend="dneirf"
echo "\n Hi, This script will show welcome message if you know name and password otherwise it will request to be friend."
echo -e "\n Enter Test Friend Name \c"
read username
echo -e "\n Enter Test Friend Password \c"
read -s password 
# -s reads silently and hence does not display on the screen

if [ ! -z $username ] && [ ! -z $password ]; # -n means not null
then
	if [ $username == $ufriend ] && [ $password == $pfriend ];
	then
		echo -e "\n Welcome, you are a old friend and old is gold. !! "
	else
		echo -e "\n Hi, You seem to be a new admission. Let's be friend. "
		echo -e "\n Use username as $ufriend and password as $pfriend going forward."
	fi
else
	echo -e "\n Either username or password is blank"
	exit 1
fi
echo -e "\n Have a nice day !"

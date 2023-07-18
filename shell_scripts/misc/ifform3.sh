#!/bin/bash
# echo calling a script with its hardlink to work differently]
# i.e. this file name is call.sh and let's say there are date.sh, cal.sh, ls.sh hard links of this original file. And when user runs this shell script
# via those hard link program behaves accordingly based on the name how it is executed. Note that $0 is the application name.
if test "$0" == "*date.sh"
then
	date
elif test "$0" == "*cal.sh"
then
	cal
elif test "$0" == "*ls.sh"
then
	ls
else
	echo "sorry"
fi

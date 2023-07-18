#/bin/bash
# Program to demo trap interrupt handling in shell script.
# This program locks the screen with user confirmed password. 
#Signal Name	Signal Number	Description
#SIGHUP		1		Hang up detected on controlling terminal or death of controlling process
#SIGINT		2		Issued if the user sends an interrupt signal (Ctrl + C).
#SIGQUIT	3		Issued if the user sends a quit signal (Ctrl + D).
#SIGFPE		8		Issued if an illegal mathematical operation is attempted
#SIGKILL	9		If a process gets this signal it must quit immediately and will not perform any clean-up operations
#SIGALRM	14		Alarm Clock signal (used for timers)
#SIGTERM	15		Software termination signal (sent by kill by default).

#[jpandya@JMP shellscripts]$ kill -l
# 1) SIGHUP       2) SIGINT       3) SIGQUIT      4) SIGILL
# 5) SIGTRAP      6) SIGABRT      7) SIGBUS       8) SIGFPE
# 9) SIGKILL     10) SIGUSR1     11) SIGSEGV     12) SIGUSR2
#13) SIGPIPE     14) SIGALRM     15) SIGTERM     16) SIGSTKFLT
#17) SIGCHLD     18) SIGCONT     19) SIGSTOP     20) SIGTSTP
#21) SIGTTIN     22) SIGTTOU     23) SIGURG      24) SIGXCPU
#25) SIGXFSZ     26) SIGVTALRM   27) SIGPROF     28) SIGWINCH
#29) SIGIO       30) SIGPWR      31) SIGSYS      34) SIGRTMIN
#35) SIGRTMIN+1  36) SIGRTMIN+2  37) SIGRTMIN+3  38) SIGRTMIN+4
#39) SIGRTMIN+5  40) SIGRTMIN+6  41) SIGRTMIN+7  42) SIGRTMIN+8
#43) SIGRTMIN+9  44) SIGRTMIN+10 45) SIGRTMIN+11 46) SIGRTMIN+12
#47) SIGRTMIN+13 48) SIGRTMIN+14 49) SIGRTMIN+15 50) SIGRTMAX-14
#51) SIGRTMAX-13 52) SIGRTMAX-12 53) SIGRTMAX-11 54) SIGRTMAX-10
#55) SIGRTMAX-9  56) SIGRTMAX-8  57) SIGRTMAX-7  58) SIGRTMAX-6
#59) SIGRTMAX-5  60) SIGRTMAX-4  61) SIGRTMAX-3  62) SIGRTMAX-2
#63) SIGRTMAX-1  64) SIGRTMAX



trap "echo 'this terminal is locked by '`whoami`" "`date` " 1 2 3 5 20
clear
echo -e "\nenter password to lock terminal:"
stty -echo
read keynew
stty echo
echo -e "\nconfirm password:"
stty -echo
read keyold
stty echo
if [ $keyold == $keynew ]
then
echo "terminal locked!"
	while [ 1 ]
	do
		echo "retype the password to unlock:"
		stty -echo
		read key
		if [ $key == $keynew ]
		then
			stty echo
			echo "terminal unlocked!"
			stty sane
		exit
		fi
		echo "invalid password!"
	done
else
	echo " passwords do not match!"
fi
stty sane

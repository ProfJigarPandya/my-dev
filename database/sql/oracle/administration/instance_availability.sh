#tnsping allows to ping and check the status of oracle instance.
#Know that it uses imap protocol in sqldeveloper test button to respond. You may need to open up that port number on server otherwise it will show error.
#
#
tnsping localhost
tnsping 192.168.29.152

#If successful, it shows status OK.
#If unsuccesful, you may need to run command on shell lsnrctl status followed by lsnrctl start

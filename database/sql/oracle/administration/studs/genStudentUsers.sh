for i in {1..10}
do
	echo "create user usr$i identified by usr$i;"
	echo "grant db_student to usr$i;"
	echo "alter user usr$i default tablespace system;"
	echo "ALTER USER usr$i QUOTA 4M ON system;"
done;
echo "commit;"
echo "exit;"
#./genStudentUsers.sh > users.sql
#sqlplus system@localhost/pdb @users.sql

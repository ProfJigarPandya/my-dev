sqlplus sys@pdb as sysdba
password
create pluggable database pdb admin user jpandya identified by jpandya roles=(DBA) file_name_convert=('/opt/oracle/oradata/XE/pdbseed','/opt/oracle/dbs/jpandyapdb/');
alter session set container=pdb;
alter pluggable database pdb open;
alter pluggable databse pdb save state;
create user scott identified by tiger;
grant connect, create session to scott;
exit

Test using below:

rlsqlplus scott/tiger@localhost/pdb

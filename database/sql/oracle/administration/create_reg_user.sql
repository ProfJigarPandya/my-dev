sqlplus sys@pdb as sysdba
password
create pluggable database pdb admin user jadmin identified by jadmin roles=(DBA) file_name_convert=('/opt/oracle/oradata/XE/pdbseed','/opt/oracle/dbs/jadminpdb/');
alter session set container=pdb;
alter pluggable database pdb open;
alter pluggable database pdb save state;
create user scott identified by tiger;
#alter user scott account unlock identified by tiger;
#grant sysdba to user_name;
grant connect, create session, create table, create trigger, create view to scott;
GRANT UNLIMITED TABLESPACE TO scott;
exit

Test using below:

rlsqlplus scott/tiger@localhost/pdb

create user usr1 identified by usr1;
grant db_student to usr1;
alter user usr1 default tablespace system;
ALTER USER usr1 QUOTA 4M ON system;
create user usr2 identified by usr2;
grant db_student to usr2;
alter user usr2 default tablespace system;
ALTER USER usr2 QUOTA 4M ON system;
create user usr3 identified by usr3;
grant db_student to usr3;
alter user usr3 default tablespace system;
ALTER USER usr3 QUOTA 4M ON system;
create user usr4 identified by usr4;
grant db_student to usr4;
alter user usr4 default tablespace system;
ALTER USER usr4 QUOTA 4M ON system;
create user usr5 identified by usr5;
grant db_student to usr5;
alter user usr5 default tablespace system;
ALTER USER usr5 QUOTA 4M ON system;
create user usr6 identified by usr6;
grant db_student to usr6;
alter user usr6 default tablespace system;
ALTER USER usr6 QUOTA 4M ON system;
create user usr7 identified by usr7;
grant db_student to usr7;
alter user usr7 default tablespace system;
ALTER USER usr7 QUOTA 4M ON system;
create user usr8 identified by usr8;
grant db_student to usr8;
alter user usr8 default tablespace system;
ALTER USER usr8 QUOTA 4M ON system;
create user usr9 identified by usr9;
grant db_student to usr9;
alter user usr9 default tablespace system;
ALTER USER usr9 QUOTA 4M ON system;
create user usr10 identified by usr10;
grant db_student to usr10;
alter user usr10 default tablespace system;
ALTER USER usr10 QUOTA 4M ON system;
commit;
exit;

set echo on;
spool create_user_master.log;

create sequence seq_user_master_user_id;

create table user_master (user_id number(5) primary key, user_name varchar2(50) not null unique,email_address varchar2(50), fname varchar2(50) not null, mname varchar2(50), lname varchar2(50) not null,
CHECK (REGEXP_LIKE (email_address, '^[a-z|0-9|\.|_]+@[a-z]+\.[a-z]+$')) );



spool off;
--exit;

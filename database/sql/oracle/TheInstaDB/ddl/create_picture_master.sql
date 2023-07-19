set echo on;
spool create_picture_master.log;

create sequence seq_picture_master_picture_id;

create table picture_master (picture_id number(5) primary key, caption varchar2(50), path varchar2(50) not null, posting_date date not null, user_id number(5) references user_master(user_id));

spool off;
--exit;

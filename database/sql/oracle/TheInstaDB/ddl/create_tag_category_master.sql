set echo on;
spool create_tag_category_master.log;

create table tag_category_master (tag_cat_id number(5) primary key, label varchar2(20) not null, description varchar2(100));

spool off;
--exit;

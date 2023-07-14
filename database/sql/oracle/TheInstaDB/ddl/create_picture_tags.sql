set echo on;
spool create_pictures_tags.log;

create sequence seq_picture_tags_tag_id;

create table picture_tags (tag_id number(7), user_id number(5) references user_master(user_id), picture_id references picture_master(picture_id), whenwas date, primary key (tag_id, user_id, picture_id));

spool off;
--exit;

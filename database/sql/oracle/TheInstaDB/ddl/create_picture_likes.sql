set echo on;
spool create_picture_likes.log;

create sequence seq_picture_likes_like_id;

create table picture_likes (like_id number(7), user_id number(5) references user_master(user_id), picture_id  number(5) references picture_master(picture_id), whenwas date, primary key (like_id, user_id, picture_id));

spool off;
--exit;

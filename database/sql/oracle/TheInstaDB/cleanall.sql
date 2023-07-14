


delete from picture_likes;
delete from picture_tags;
delete from tag_category_master;
delete from picture_master;
delete from user_master;

drop sequence seq_user_master_user_id;
drop sequence seq_picture_master_picture_id;
drop sequence seq_picture_tags_tag_id;
drop sequence seq_picture_likes_like_id;


drop table picture_likes;
drop table picture_tags;
drop table tag_category_master;
drop table picture_master;
drop table user_master;



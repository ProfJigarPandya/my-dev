select * from user_master;
select * from picture_master;
select * from tag_category_master;
select * from picture_likes;
select * from picture_tags;

select seq_user_master_user_id.currval from dual;
select seq_picture_master_picture_id.currval from dual;
select seq_picture_tags_tag_id.currval from dual;
select seq_picture_likes_like_id.currval from dual;
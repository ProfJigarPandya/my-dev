set echo on;
spool runall.log;

@ddl/create_user_master.sql;
@ddl/create_picture_master.sql;
@ddl/create_tag_category_master.sql;
@ddl/create_picture_tags.sql;
@ddl/create_picture_likes.sql;


spool off;
exit;


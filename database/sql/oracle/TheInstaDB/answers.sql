--1.Display Picture ids of pictures posted by user id “1”
select picture_id from picture_master  natural join user_master where user_id='1';


--2. Display captions of pictures posted by “2”. Display ‘No caption’ if caption is not having any value.
select nvl(caption, 'No caption') from picture_master  natural join user_master where user_id='2';

--3. Which pictures (picture ids) and by which users (user ids) have be in posted in last 1 year?
select picture_id, user_id from picture_master natural join user_master where trunc(POSTING_DATE) between trunc(sysdate)-INTERVAL'1'year and trunc(sysdate);


--4. Which picture/s (picture ids) has received maximum likes?
select picture_id, count(like_id) from picture_likes where rownum<2 group by picture_id order by picture_id desc;

(SELECT DISTINCT picture_id FROM picture_likes) minus
  (SELECT DISTINCT ls.picture_id picture_id
  FROM
    (SELECT picture_id,
      COUNT(like_id) totallk
    FROM picture_likes
    GROUP BY picture_id
    ) ls,
    (SELECT picture_id,
      COUNT(like_id) totallk
    FROM picture_likes
    GROUP BY picture_id
    )  mr WHERE ls.totallk < mr. totallk);

--5. Display all picture ids in descending order of the likes they have got. Also display total no. of likes each picture has received.
select picture_id, count(like_id) from picture_likes group by picture_id order by 2 desc;



--6. Display picture ids of pictures with more than 3 likes.
select picture_id, count(like_id) from picture_likes group by picture_id having count(like_id) > 3;

--7. Who (user id) has liked the most pictures?
(SELECT DISTINCT user_id FROM picture_likes) minus
  (SELECT DISTINCT ls.user_id picture_id
  FROM
    (SELECT user_id,
      COUNT(like_id) totallk
    FROM picture_likes
    GROUP BY user_id
    ) ls,
    (SELECT user_id,
      COUNT(like_id) totallk
    FROM picture_likes
    GROUP BY user_id
    )  mr WHERE ls.totallk < mr. totallk);

--8. Which day of the week users are posting the maximum no. of pictures?

SELECT DISTINCT TO_CHAR(posting_date, 'DAY') FROM PICTURE_MASTER
MINUS
  (SELECT TO_CHAR(ls.posting_date,'DAY')
  FROM
    (SELECT posting_date,
      COUNT(picture_id) totalcount
    FROM PICTURE_MASTER
    GROUP BY posting_date
    ) ls,
    (SELECT posting_date,
      COUNT(picture_id) totalcount
    FROM PICTURE_MASTER
    GROUP BY posting_date
    ) mr
  WHERE ls.totalcount< mr. totalcount
  ) ;

--9. Get the count of pictures posted during weekends.
select count(*) picture_Posted_During_Weekends from picture_master where to_char(POSTING_DATE,'DY') in ('SAT', 'SUN');


--10. Find pictures (picture ids) with more than 3 tags.
select picture_id from picture_tags group by picture_id having count(tag_id) > 3;

--11. Display pictures with “London” in their caption. Do case insensitive search.
select picture_id, caption from picture_master where lower(caption) like '%london%';

--12. Which pictures (picture ids) are stored on my “D:” drive?
select picture_id, path from picture_master where lower(path) like 'd:%';

--13. Display year, pic_id of pictures posted by User id -3 in last 5 years.
select EXTRACT(YEAR FROM posting_date) FROM picture_master where user_id='3' and trunc(posting_date) between trunc(posting_date) - interval '5' year and trunc(sysdate);

--14. Display first and last names of all users who have either have an account on gmail or yahoo.
select fname, lname from user_master where lower(REGEXP_SUBSTR(EMAIL_ADDRESS, '@[^.]+')) in ('@gmail','@yahoo'); 

--15. Add new user with user-name, his first & last name and email.
insert into user_master (user_id, user_name, fname, lname, email_address) values(seq_user_master_user_id.nextval,:user_name,:fname,:lname,:email_address);


--16. Add a like for Picture id 6 by user id 7.
insert into picture_like (picture_id, caption, path, posting_date, user_id ) values (seq_picture_master_picture_id.nextval, :caption, :path, :posting_date, :user_id);
--17. Delete all likes done by user id ‘3’.

--18. Update last name for user id ‘9’ to ‘Kumar’.
update user_master set lname='Kumar' where user_id='9';

--19. Update email address of User “Angella Smith” to asmith@gmail.com.
update user_master set email_address='asmith@gmail.com' where lower(fname)='angella' and lower(lname)='smith';

--20. Add a new tag for “Literature”.
insert into tag_catetory_master ( tag_category_id, label, description) values ((select nvl(max(tag_cat_id)+1,1) from tag_category_master),:label,:description);

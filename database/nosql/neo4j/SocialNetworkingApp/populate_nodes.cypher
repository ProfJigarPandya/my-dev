UNWIND range(1,5) AS id
CREATE (p:PersonNode {
    person_id: id,
    person_name: 'Person ' + id,
    person_age: 20 + id,
    person_location: 'Location ' + id,
    person_email: 'person' + id + '@example.com'
});


UNWIND range(1,2) AS id
CREATE (p:PostNode {
    post_id: id,
    post_name: 'Post ' + id,    
    post_description: 'This is the content of post ' + id,
    post_timestamp: datetime() - duration({days: id}),
    post_likes_count: 0,
    post_comments_count: 0
});


UNWIND range(1,4) AS id
CREATE (c:CommentNode {
    comment_id: id,
    comment_name: 'Comment ' + id,    
    comment_description: 'This is the content of comment ' + id,
    comment_timestamp: datetime() - duration({hours: id}),
    comment_likes_count: 0
});




UNWIND range(1,5) AS id
CREATE (l:LocationNode {
    location_id: id,
    location_name: 'Location ' + id
});    
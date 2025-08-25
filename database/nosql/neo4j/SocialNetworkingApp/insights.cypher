CALL db.labels() YIELD label
RETURN label;

MATCH (n)
RETURN DISTINCT labels(n);

CALL db.relationshipTypes() YIELD relationshipType
RETURN relationshipType;

MATCH (n)-[r]->(m)
RETURN DISTINCT TYPE(r);


MATCH (n)
OPTIONAL MATCH (n)-[r]->(m)
RETURN n,r,m;

MATCH (n)
RETURN labels(n) as nodeLabels, COUNT(n) AS nodeCount;

MATCH (n)-[r]->(m)
RETURN TYPE(r) as relationshipType, COUNT(r) AS relationshipCount
order by relationshipCount desc;



MATCH (person:PersonNode)-[r:PERSON_CREATED_POST]->(post:PostNode)
WITH person.person_name AS author, post.post_name AS postTitle, r.created_at AS createdAt
RETURN author, postTitle, createdAt;

CALL db.relationshipTypes() YIELD relationshipType
MATCH ()-[r:$(relationshipType)]->()
RETURN relationshipType, COUNT(r) AS relationshipCount
order by relationshipCount desc;

MATCH (n)-[r:PERSON_CREATED_COMMENT]->(m)
return n.person_name, m.comment_description, r.commented_at;



MATCH (n:PersonNode)-[r:FRIENDS_WITH]->(m:PersonNode)
return n.person_name, m.person_name, r.since;



//Retrieve all friends of Person 1
MATCH (per1:PersonNode {person_name:"Person 1"})-[r:FRIENDS_WITH]->(per2:PersonNode)
return per1.person_name, per2.person_name, r.since;

MATCH (per1:PersonNode )-[r:FRIENDS_WITH]->(per2:PersonNode)
WHERE per1.person_name = "Person 1"
return per1.person_name, per2.person_name, r.since;

MATCH (per1:PersonNode )-[r:FRIENDS_WITH]->(per2:PersonNode)
WHERE per1.person_name = "Person 1"
return per1.person_name, collect(per2.person_name) as friends;


//Retrieve all posts created by Person 1 and their associated comments
UNWIND range(1,5) AS iter
MATCH (person:PersonNode )-[rpp:PERSON_CREATED_POST]->(post:PostNode)
WHERE person.person_name = "Person "+iter
MATCH (comment:CommentNode)-[rcp:COMMENT_ATTACHED_TO_POST]->(post:PostNode)
return person.person_name, post.post_description, collect(comment.comment_id) as comments;


//Retrieve all comments made on Post 1 along with the commenters' details
MATCH (post:PostNode {post_name:"Post 1" })<-[rcp:COMMENT_ATTACHED_TO_POST]-(comment:CommentNode)
MATCH (person:PersonNode)-[rpc:PERSON_CREATED_COMMENT]->(comment:CommentNode)
return post.post_name, comment.comment_description, person.person_name, person.person_email;


//Find mutual friends between Person 1 and Person 2
MATCH (p1:PersonNode {person_name:"Person 1"})-[:FRIENDS_WITH]-(mutualFriend:PersonNode)-[:FRIENDS_WITH]-(p2:PersonNode {person_name:"Person 2"})
RETURN distinct mutualFriend.person_name AS MutualFriend;

MATCH (p1:PersonNode {person_name:"Person 2"})-[:FRIENDS_WITH]-(mutualFriend:PersonNode)-[:FRIENDS_WITH]-(p2:PersonNode {person_name:"Person 4"})
RETURN distinct mutualFriend.person_name AS MutualFriend;

MATCH (p1:PersonNode {person_name:"Person 1"})-[:FRIENDS_WITH]-(mutualFriend:PersonNode)-[:FRIENDS_WITH]-(p2:PersonNode {person_name:"Person 4"})
RETURN distinct mutualFriend.person_name AS MutualFriend;

MATCH (p1:PersonNode {person_name:"Person 1"})-[:FRIENDS_WITH]-(mutualFriend:PersonNode)-[:FRIENDS_WITH]-(p2:PersonNode {person_name:"Person 5"})
RETURN distinct mutualFriend.person_name AS MutualFriend;

//Find friends of friends for Person 1
MATCH (p:PersonNode {person_name:"Person 1"})-[:FRIENDS_WITH]-(friend)-[:FRIENDS_WITH]-(fof)
WHERE NOT (p)-  [:FRIENDS_WITH]-(fof) AND p <> fof
RETURN DISTINCT fof.person_name AS FriendsOfFriends;    

//Count the number of posts created by each person
MATCH (person:PersonNode)-[r:PERSON_CREATED_POST]->(post:PostNode)
RETURN person.person_name AS Author, COUNT(post) AS NumberOfPosts ;          

//Count the number of comments on each post
MATCH (post:PostNode)<-[r:COMMENT_ATTACHED_TO_POST]-(comment:CommentNode)
RETURN post.post_name AS PostTitle, COUNT(comment) AS NumberOfComments
ORDER BY NumberOfComments DESC;

//Count the number of friends each person has
MATCH (person:PersonNode)-[r:FRIENDS_WITH]-(friend:PersonNode)
RETURN person.person_name AS Person, COUNT(friend)/2 AS NumberOfFriends, 
collect(distinct friend.person_name) AS FriendsList
ORDER BY NumberOfFriends DESC;       

//Find the most active commenters (those who have made the most comments)
MATCH (person:PersonNode)-[r:PERSON_CREATED_COMMENT]->(comment:CommentNode)
RETURN person.person_name AS Commenter, COUNT(comment) AS NumberOfComments
ORDER BY NumberOfComments DESC
LIMIT 1;

//Find the posts with the highest number of comments
MATCH (post:PostNode)<-[r:COMMENT_ATTACHED_TO_POST]-(comment:   CommentNode)
RETURN post.post_name AS PostTitle, COUNT(comment) AS NumberOfComments
ORDER BY NumberOfComments DESC
LIMIT 1;

//Find people who have commented on their own posts
MATCH (person:PersonNode)-[r1:PERSON_CREATED_POST]->(post:PostNode)
MATCH (person)-[r2:PERSON_CREATED_COMMENT]->(comment:CommentNode)-[r3:COMMENT_ATTACHED_TO_POST]->(post)
RETURN DISTINCT person.person_name AS Person, post.post_name AS PostTitle, comment.comment_description AS CommentDescription;       

//Find people who have commented on posts created by their friends
MATCH (person:PersonNode)-[r1:FRIENDS_WITH]-(friend:PersonNode)-[r2:PERSON_CREATED_POST]->(post:PostNode)
MATCH (person)-[r3:PERSON_CREATED_COMMENT]->(comment:CommentNode)-[r4:COMMENT_ATTACHED_TO_POST]->(post)
RETURN DISTINCT person.person_name AS Person, friend.person_name AS Friend, post.post_name AS PostTitle, comment.comment_description AS CommentDescription; 

//Find the average number of comments per post
MATCH (post:PostNode)
OPTIONAL MATCH (post)<-[r:COMMENT_ATTACHED_TO_POST]-(comment:CommentNode)
WITH post, COUNT(comment) AS NumberOfComments
RETURN AVG(NumberOfComments) AS AverageCommentsPerPost; 


//Find the average number of friends per person
MATCH (person:PersonNode)
OPTIONAL MATCH (person)-[r:FRIENDS_WITH]-(friend:PersonNode )
WITH person, COUNT(friend)/2 AS NumberOfFriends
RETURN AVG(NumberOfFriends) AS AverageFriendsPerPerson;

//Find the average number of posts per person
MATCH (person:PersonNode)
OPTIONAL MATCH (person)-[r:PERSON_CREATED_POST]->(post:PostNode)                        
WITH person, COUNT(post) AS NumberOfPosts
RETURN AVG(NumberOfPosts) AS AveragePostsPerPerson;

//Find the mutual friends with all pairs of people
MATCH (p1:PersonNode)-[:FRIENDS_WITH]-(mutualFriend:PersonNode)-[:FRIENDS_WITH]-(p2:PersonNode)
WHERE p1.person_id < p2.person_id
RETURN p1.person_name AS Person1, p2.person_name AS Person2, collect(DISTINCT mutualFriend.person_name) AS MutualFriends, COUNT(DISTINCT mutualFriend) AS NumberOfMutualFriends;
MATCH (person:PersonNode {person_name:"Person 1"}), (post:PostNode {post_name:"Post 1" })
WITH person, post
CREATE (person)-[:PERSON_CREATED_POST {created_at: datetime()}]->(post);

MATCH (person:PersonNode {person_name:"Person 2"}), (post:PostNode {post_name:"Post 2" })
WITH person, post
CREATE (person)-[:PERSON_CREATED_POST {created_at: datetime()}]->(post);


MATCH (person:PersonNode {person_name:"Person 1"}), (post:PostNode {post_name:"Post 1" }), (comment:CommentNode {comment_name:"Comment 1" })
CREATE (person)-[:PERSON_CREATED_COMMENT {commented_at: datetime()}]->(comment)
CREATE (comment)-[:COMMENT_ATTACHED_TO_POST {commented_at: datetime()}]->(post);

MATCH (person:PersonNode {person_name:"Person 2"}), (post:PostNode {post_name:"Post 1" }), (comment:CommentNode {comment_name:"Comment 2" })
CREATE (person)-[:PERSON_CREATED_COMMENT {commented_at: datetime()}]->(comment)
CREATE (comment)-[:COMMENT_ATTACHED_TO_POST {commented_at: datetime()}]->(post);

MATCH (person:PersonNode {person_name:"Person 5"}), (post:PostNode {post_name:"Post 1" }), (comment:CommentNode {comment_name:"Comment 3" })
CREATE (person)-[:PERSON_CREATED_COMMENT {commented_at: datetime()}]->(comment)
CREATE (comment)-[:COMMENT_ATTACHED_TO_POST {commented_at: datetime()}]->(post);


MATCH (person:PersonNode {person_name:"Person 5"}), (post:PostNode {post_name:"Post 2" }), (comment:CommentNode {comment_name:"Comment 4" })
CREATE (person)-[:PERSON_CREATED_COMMENT {commented_at: datetime()}]->(comment)
CREATE (comment)-[:COMMENT_ATTACHED_TO_POST {commented_at: datetime()}]->(post);



//Peson1, Person2 are friends
MATCH (personA:PersonNode {person_name:'Person 1'}), (personB:PersonNode {person_name:'Person 2'})
WITH personA, personB
WHERE
  personA.person_id <> personB.person_id // Prevent self-friendship
CREATE (personA)-[:FRIENDS_WITH {since: date()}]->(personB)
CREATE (personA)<-[:FRIENDS_WITH {since: date()}]-(personB);

//Peson1, Person4 are friends
MATCH (personA:PersonNode {person_name:'Person 1'}), (personB:PersonNode {person_name:'Person 4'})
WITH personA, personB
WHERE
  personA.person_id <> personB.person_id // Prevent self-friendship
CREATE (personA)-[:FRIENDS_WITH {since: date()}]->(personB)
CREATE (personA)<-[:FRIENDS_WITH {since: date()}]-(personB);

//Peson1, Person5 are friends
MATCH (personA:PersonNode {person_name:'Person 1'}), (personB:PersonNode {person_name:'Person 5'})
WITH personA, personB
WHERE
  personA.person_id <> personB.person_id // Prevent self-friendship
CREATE (personA)-[:FRIENDS_WITH {since: date()}]->(personB)
CREATE (personA)<-[:FRIENDS_WITH {since: date()}]-(personB);


//Peson2, Person4 are friends
MATCH (personA:PersonNode {person_name:'Person 2'}), (personB:PersonNode {person_name:'Person 4'})
WITH personA, personB
WHERE
  personA.person_id <> personB.person_id // Prevent self-friendship
CREATE (personA)-[:FRIENDS_WITH {since: date()}]->(personB)
CREATE (personA)<-[:FRIENDS_WITH {since: date()}]-(personB);

//Peson2, Person5 are friends
MATCH (personA:PersonNode {person_name:'Person 2'}), (personB:PersonNode {person_name:'Person 5'})
WITH personA, personB
WHERE
  personA.person_id <> personB.person_id // Prevent self-friendship
CREATE (personA)-[:FRIENDS_WITH {since: date()}]->(personB)
CREATE (personA)<-[:FRIENDS_WITH {since: date()}]-(personB);

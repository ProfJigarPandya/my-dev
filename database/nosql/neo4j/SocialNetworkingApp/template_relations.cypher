
//Generate connections for following relations:

//FRIENDS_WITH: Represents the friendship relationship between two users. 
//Having​ properties: since (the date when the friendship started)
CREATE (person1:PersonNode)-[rfriend:FRIENDS_WITH {since: date()}]->(person2:PersonNode)
return rfriend;

//CREATED: Represents a user creating a post. 
//Having properties: created_at (timestamp when the post was created)
CREATE (person:PersonNode)-[rcreated:CREATED {created_at: datetime()}]->(post:PostNode)       
return rcreated;


//COMMENTED: Represents a user commenting on a post. 
//Having properites : commented_at (timestamp when the comment was made)
CREATE (person:PersonNode)-[rcommented:COMMENTED {commented_at: datetime()}]->(comment:CommentNode)
return rcommented;

//LOCATED_IN: (Optional) Connects a user to a location. 
//Having properties : since (timestamp when the user joined this location)
CREATE (person:PersonNode)-[rlocated:LOCATED_IN {since: datetime()}]->(location:LocationNode)
return rlocated;
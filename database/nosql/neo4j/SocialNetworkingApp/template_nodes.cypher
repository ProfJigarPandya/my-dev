//Create user node with properties user_id, name, age, location, email
// Example:                     
create (user:PersonNode {
    person_id: '',
    name: '',
    age: 0,
    location: '',
    email:''})
return user;


//Create post node with properties post_id, content, timestamp, likes_count, comments_count
// Example:
create (post:PostNode {
    post_id: '',
    content: '',
    timestamp: datetime(),
    likes_count: 0,
    comments_count: 0})
return post;

//Create comment node with properties comment_id, content, timestamp, likes_count   
// Example:
create (comment:CommentNode {
    comment_id: '',
    content: '',
    timestamp: datetime(),
    likes_count: 0})
return comment;

//Create location node (Optional) If you're going to query based on location properties: location_name
// Example:
create (location:LocationNode {
    location_name: ''})
return location;


/*
//Create tag node with properties tag_id, name
// Example:
create (tag:TagNode {
    tag_id: '',
    name: ''})
return tag;     

//Create group node with properties group_id, name, description, member_count
// Example:
create (group:GroupNode {
    group_id: '',
    name: '',
    description: '',
    member_count: 0})
return group;

//Create event node with properties event_id, name, description, date, location
// Example:
create (event:EventNode {
    event_id: '',
    name: '',
    description: '',
    date: date(),
    location: ''})
return event;   
*/

//CREATE(:Device)-[:CONNECTED_TO]->(:Device) 
MATCH (c1:Device {name: "Audio"})
MATCH (c2:Device {type: "Entertainment"})
CREATE (c1)-[:AccessoryOf]->(c2);

MATCH (c1:Device {type: "Input"})
MATCH (c2:Device {type: "Computer"})
CREATE (c1)-[:NecessaryFor]->(c2);

MATCH (c1:Device {type: "Output"})
MATCH (c2:Device {type: "Computer"})
CREATE (c1)-[:NecessaryFor]->(c2);

MATCH (c1:Device {type: "Display"})
MATCH (c2:Device {type: "Computer"})
CREATE (c1)-[:NecessaryFor]->(c2);

MATCH (c1:Device {type: "Computer"})
MATCH (c2:Device {type: "Gaming"})
CREATE (c1)-[:NecessaryFor]->(c2);

MATCH (c1:Device {type: "Audio"})
MATCH (c2:Device {type: "Gaming"})
CREATE (c1)-[:AccessoryOf]->(c2);

MATCH (c1:Device {type: "Networking"})
MATCH (c2:Device {type: "Gaming"})
CREATE (c1)-[:NecessaryFor]->(c2);

MATCH (c1:Device {type: "Networking"})
MATCH (c2:Device {type: "Computer"})
CREATE (c1)-[:NecessaryFor]->(c2);



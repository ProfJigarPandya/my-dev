//CREATE(:Device)-[:CONNECTED_TO]->(:Device) 
MATCH (c1:Device {name: "Bluetooth Speaker"})
MATCH (c2:Device {name: "Smartphone"})
CREATE (c1)-[:AccessoryOf]->(c2);

MATCH (c3:Device {name: "Wireless Earbuds"})
MATCH (c4:Device {name: "Smartphone"})
CREATE (c3)-[:AccessoryOf]->(c4);   

MATCH (c5:Device {type: "Input"})
MATCH (c6:Device {type: "Computer"})  
CREATE (c5)-[:providesInformation]->(c6);

MATCH (c7:Device {type: "Computer"})
MATCH (c8:Device {type: "Output"})  
CREATE (c7)-[:generatesResult]->(c8);

MATCH (c9:Device {type: "Computer"})
MATCH (c10:Device {type: "Display"})  
CREATE (c9)-[:generatesResult]->(c10);

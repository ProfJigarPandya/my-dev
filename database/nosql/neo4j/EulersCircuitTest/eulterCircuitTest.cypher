
MATCH ()-[r]->()
DELETE r;

MATCH (n)
DETACH DELETE n;


CREATE(:landArea {name: "landNorthAltstadt", displayOrder:1, comments:"This is land towards the north. It is called Altstadt."});
CREATE(:landArea {name: "landIslandKneiphof", displayOrder:2, comments:"This is an island. It is called Kneiphof."});
CREATE(:landArea {name: "landEastLomse", displayOrder:3, comments:"This is land towards the east.   It is called Lomse."});
CREATE(:landArea {name: "landSouthVorstadt", displayOrder:4, comments:"This is land towards the south. it is called Vorstadt."});


MATCH (s:landArea {name:"landNorthAltstadt"})
MATCH (d:landArea {name:"landIslandKneiphof"})
CREATE(s)<-[:bridge {number:"1"}]-(d)
CREATE(s)-[:bridge {number:"1"}]->(d);

MATCH (s:landArea {name:"landNorthAltstadt"})
MATCH (d:landArea {name:"landIslandKneiphof"})
CREATE(s)<-[:bridge {number:"2"}]-(d)
CREATE(s)-[:bridge {number:"2"}]->(d);


MATCH (s:landArea {name:"landNorthAltstadt"})
MATCH (d:landArea {name:"landEastLomse"})
CREATE(s)<-[:bridge {number:"3"}]-(d)
CREATE(s)-[:bridge {number:"3"}]->(d);


MATCH (s:landArea {name:"landIslandKneiphof"})
MATCH (d:landArea {name:"landEastLomse"})
CREATE(s)<-[:bridge {number:"4"}]-(d)
CREATE(s)-[:bridge {number:"4"}]->(d);


MATCH (s:landArea {name:"landSouthVorstadt"})
MATCH (d:landArea {name:"landIslandKneiphof"})
CREATE(s)<-[:bridge {number:"5"}]-(d)
CREATE(s)-[:bridge {number:"5"}]->(d);


MATCH (s:landArea {name:"landSouthVorstadt"})
MATCH (d:landArea {name:"landIslandKneiphof"})
CREATE(s)<-[:bridge {number:"6"}]-(d)
CREATE(s)-[:bridge {number:"6"}]->(d);

MATCH (s:landArea {name:"landSouthVorstadt"})
MATCH (d:landArea {name:"landEastLomse"})
CREATE(s)<-[:bridge {number:"7"}]-(d)
CREATE(s)-[:bridge {number:"7"}]->(d);

//A graph is eulerian if all vertices have even degree.
//Let's check the degree of each vertex. As neo4j allows only directed edges, we will count the number of incoming and outgoing edges for each vertex.
//To identify corresponding edges, we have used number property of the bridge relationship.

MATCH (n:landArea)
OPTIONAL MATCH (n)<-[r:bridge]-(m)
WITH n, count(r) AS incomingEdges, collect(r.number) AS incomingNumbers
OPTIONAL MATCH (n)-[r:bridge]->(m)
WITH n, incomingEdges, incomingNumbers, count(r) AS outgoingEdges, collect(r.number) AS outgoingNumbers
WHERE incomingEdges > 0 
AND outgoingEdges > 0 
AND incomingEdges = outgoingEdges
AND incomingNumbers = outgoingNumbers
AND (incomingEdges % 2) = 0
WITH collect(n) AS eulerianNodes
MATCH (la:landArea)
WITH eulerianNodes, count(la) AS totalLandArea
RETURN 
CASE WHEN size(eulerianNodes) = totalLandArea
 THEN 'YES' ELSE 'NO' END AS isEulerian;


MATCH (n:landArea)
OPTIONAL MATCH (n)<-[r:bridge]-(m)
WITH n, count(r) AS incomingEdges, collect(r.number) AS incomingNumbers
OPTIONAL MATCH (n)-[r:bridge]->(m)
WITH n, incomingEdges, incomingNumbers, count(r) AS outgoingEdges, collect(r.number) AS outgoingNumbers
WHERE incomingEdges > 0 
AND outgoingEdges > 0 
AND incomingEdges = outgoingEdges
AND incomingNumbers = outgoingNumbers
RETURN n.name AS landArea, size(outgoingNumbers) AS degree;



MATCH (n)
OPTIONAL MATCH (n)-[r]->(m)
RETURN n, r, m
LIMIT 50;
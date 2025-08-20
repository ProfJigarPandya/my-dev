const neo4j = require('neo4j-driver');

const driver = neo4j.driver('bolt://localhost:7687', neo4j.auth.basic('neo4j', 'neo4j'));
const session = driver.session();

async function createGraph() {
    const createPersonQuery = `
        CREATE (p:Person {name: $name})
        RETURN p
    `;

    const createBelongingQuery = `
        MATCH (p:Person {name: $personName})
        CREATE (b:Belonging {item: $item})
        CREATE (p)-[:OWNS]->(b)
        RETURN b
    `;

    try {
        const personName = 'John Doe';
        await session.run(createPersonQuery, { name: personName });

        const belongings = ['Laptop', 'Phone', 'Watch'];
        for (const item of belongings) {
            await session.run(createBelongingQuery, { personName, item });
        }

        console.log('Graph created with person and belongings.');
    } catch (error) {
        console.error('Error creating graph:', error);
    } finally {
        await session.close();
        await driver.close();
    }
}

createGraph();

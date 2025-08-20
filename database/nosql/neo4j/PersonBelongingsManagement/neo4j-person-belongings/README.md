# Neo4j Person and Belongings

This project demonstrates how to use Neo4j to model a graph of persons and their belongings. It provides a simple structure to represent relationships between individuals and the items they own.

## Project Structure

```
neo4j-person-belongings
├── src
│   ├── index.js          # Entry point of the application
│   └── models
│       └── person.js     # Model for the Person class
├── package.json          # NPM configuration file
└── README.md             # Project documentation
```

## Setup Instructions

1. **Clone the repository:**
   ```
   git clone https://github.com/yourusername/neo4j-person-belongings.git
   cd neo4j-person-belongings
   ```

2. **Install dependencies:**
   ```
   npm install
   ```

3. **Set up Neo4j:**
   - Ensure you have a running instance of Neo4j.
   - Update the connection details in `src/index.js` to match your Neo4j configuration.

## Usage

1. **Run the application:**
   ```
   node src/index.js
   ```

2. **Creating a Person:**
   You can create a new person and add belongings using the `Person` class defined in `src/models/person.js`.

3. **Example:**
   ```javascript
   const Person = require('./models/person');

   const john = new Person('John Doe');
   john.addBelonging('Laptop');
   console.log(john.getBelongings());
   ```

## Contributing

Feel free to submit issues or pull requests to improve the project. 

## License

This project is licensed under the MIT License.
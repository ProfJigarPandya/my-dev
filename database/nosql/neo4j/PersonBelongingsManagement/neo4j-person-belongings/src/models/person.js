class Person {
    constructor(name) {
        this.name = name;
        this.belongings = [];
    }

    addBelonging(belonging) {
        this.belongings.push(belonging);
    }

    getBelongings() {
        return this.belongings;
    }
}

module.exports = Person;
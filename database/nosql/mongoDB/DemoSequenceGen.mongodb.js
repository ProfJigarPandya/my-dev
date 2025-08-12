// Select the database to use.
use('mongodbVSCodePlaygroundDB');

db.usercounters.remove({})

function getnextseq(name) {
    var ret = db.usercounters.findAndModify({
        query:{ _id: name },
        update: { $inc: { seq: 1 } },
        new: true
    });
    return ret.seq;
}

db.usercounters.insert(
    {
        _id: "empid",
        seq: 0
    })

db.usercounters.insertOne(
    {
        _id: getnextseq("empid"),
        name: "Ray Deen"
    })

db.usercounters.insertOne(
    {
        _id: getnextseq("empid"),
        name: "Tom Jerry"
    })
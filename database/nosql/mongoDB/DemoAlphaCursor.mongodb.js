use('mongodbVSCodePlaygroundDB');

db.alphabets.remove({})

db.alphabets.insertOne({_id:1,alphabet:"a"})
db.alphabets.insertOne({_id:2,alphabet:"b"})
db.alphabets.insertOne({_id:3,alphabet:"c"})
db.alphabets.insertOne({_id:4,alphabet:"d"})
db.alphabets.insertOne({_id:5,alphabet:"e"})
db.alphabets.insertOne({_id:6,alphabet:"f"})
db.alphabets.insertOne({_id:7,alphabet:"g"})
db.alphabets.insertOne({_id:8,alphabet:"h"})
db.alphabets.insertOne({_id:9,alphabet:"i"})
db.alphabets.insertOne({_id:10,alphabet:"j"})
db.alphabets.insertOne({_id:11,alphabet:"k"})
db.alphabets.insertOne({_id:12,alphabet:"l"})
db.alphabets.insertOne({_id:13,alphabet:"m"})
db.alphabets.insertOne({_id:14,alphabet:"n"})
db.alphabets.insertOne({_id:15,alphabet:"o"})
db.alphabets.insertOne({_id:16,alphabet:"p"})
db.alphabets.insertOne({_id:17,alphabet:"q"})
db.alphabets.insertOne({_id:18,alphabet:"r"})
db.alphabets.insertOne({_id:19,alphabet:"s"})
db.alphabets.insertOne({_id:20,alphabet:"t"})
db.alphabets.insertOne({_id:21,alphabet:"u"})
db.alphabets.insertOne({_id:22,alphabet:"v"})
db.alphabets.insertOne({_id:23,alphabet:"w"})
db.alphabets.insertOne({_id:24,alphabet:"x"})
db.alphabets.insertOne({_id:25,alphabet:"y"})
db.alphabets.insertOne({_id:26,alphabet:"z"})


db.alphabets.ensureIndex({"alphabet":1});


var myCur= db.alphabets.find({})


while(myCur.hasNext()){
	var myRec=myCur.next()
	print("The alphabet is : "+myRec.alphabet);
}
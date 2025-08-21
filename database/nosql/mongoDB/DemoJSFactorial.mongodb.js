// Select the database to use.
use('mongodbVSCodePlaygroundDB');

db.system.js.find({})


/*db.system.js.insert({
    _id:"factorial",
        value:function(n)
        {
            if(n==1)
                return 1;
            else   
                return n * factorial(n-1);   
        }
    }
);*/

//db.system.js.find({});

//db.eval(x="factorial(1)");

//db.eval(x="factorial(5)");

//db.loadServerScripts()





db.system.js.insert({
    _id:"factorial",
        value:function(n)
        {
            if(n==1)
                return 1;
            else   
                return n * factorial(n-1);   
        }
    }
);
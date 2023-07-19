L=[3,1,4,5,7,6,2]
print("Before sorting")
for i in L:
    print (i,end=" ");
len=len(L)
print("Total records are ",len)
for i in range(0,len-1):
    print("Loop ",i)
    dMin=min(L[i:])
    j=L.index(dMin)
    L[i:j+1]=reversed(L[i:j+1])
    print(L)
print("After Sorting")
print(L)

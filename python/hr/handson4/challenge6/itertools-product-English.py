# Enter your code here. Read input from STDIN. Print output to STDOUT
from itertools import product
list1=list(map(int,input().split()))
#print(list1)
list2=list(map(int,input().split()))
#print(list2)
result=product(list1,list2)
print(*result,end='')#it treats each element in the tuple as a separate argument to the print() function. 


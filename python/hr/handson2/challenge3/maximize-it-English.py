#https://www.hackerrank.com/challenges/maximize-it
line1=list(map(int, input().split()))
K=line1[0]
M=line1[1]
#print(K)
#print(M)


lists = []
for l in range(K):
    lists.append([])
    line = list(map(int, input().split()))
    for element in range(1,line[0]+1):
        lists[l].append(line[element])

#print(lists)
for l in range(K):
    lists[l].sort(reverse=True)

max_sum=0

for l in range(K):
        max_sum+=lists[l][0]**2

if max_sum%M!=0:
    print(max_sum%M)
else:
   pass
    

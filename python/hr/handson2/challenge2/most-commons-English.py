#https://www.hackerrank.com/challenges/most-commons
#https://docs.python.org/3/howto/sorting.html
#!/bin/python3

from collections import Counter



s = input()
c = Counter(s)
most_common = c.most_common()
most_common.sort(key=lambda x: (-x[1], x[0]))
for a,b in most_common[0:2]:
    print(a,b)
a,b=most_common[2]
print(a,b,end='')

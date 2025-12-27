#!/bin/python3

from collections import Counter

s = input()
c = Counter(s)
l = list()
for item in c.items():
	l.append(item)
	l.sort(key=lambda x: (-x[1], x[0]))
	for a,b in l[0:3]:
        print(a,b)

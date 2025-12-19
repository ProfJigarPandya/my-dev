from collections import Counter

records=[]
grades=[]
for _ in range(int(input())):
	name = input()
	score = float(input())
	record=[]
	record.append(name)
	record.append(score)
	grades.append(score)
	records.append(record)
c = Counter(grades)      
second_lowest = sorted(c)[1]
result_list = []
for record in records:
	if record[1] == second_lowest:
		result_list.append(record[0])
result_list.sort()
number_of_names=len(result_list)   
for i in range(number_of_names-1):
	print(result_list[i])
print(result_list[number_of_names-1],end='')

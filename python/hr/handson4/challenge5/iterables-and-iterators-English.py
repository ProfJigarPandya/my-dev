# Enter your code here. Read input from STDIN. Print output to STDOUT
from itertools import combinations
length_of_list_N=input()
#print(length_of_list_N)

english_letters = input().split()
#for el in english_letters:
#    print(el)
    
number_of_indices_K=int(input().strip())
#print(number_of_indices_K)

count_of_a = 0
total_pairs=0
comb=combinations(english_letters,number_of_indices_K)

for c in comb:
#    print(c)
    if(c.__contains__('a')):
        count_of_a=count_of_a+1
    total_pairs=total_pairs+1
#print(count_of_a)
#print(total_pairs)
result=count_of_a/total_pairs
print(f"{result:.12g}",end='')

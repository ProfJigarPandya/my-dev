#https://www.hackerrank.com/challenges/maximize-it
line1=list(map(int, input().split()))
number_of_lines_K=line1[0]
modulo_M=line1[1]
#print(number_of_lines_K)   
#print(module_M)
if(number_of_lines_K==0):
    print(0)
    exit()

lists = []
for l in range(number_of_lines_K):
    lists.append([])
    line = list(map(int, input().split()))
    for element in range(1,line[0]+1):
        lists[l].append(line[element])
#print(lists)

if(number_of_lines_K==1):
    line = lists[0]
    maximized_result=(line[0]*line[0])%modulo_M   
    for prospective_element in line[1:]:
        if((prospective_element*prospective_element)%modulo_M>maximized_result):
            maximized_result = (prospective_element*prospective_element)%modulo_M
    print(maximized_result,end='')
    exit()          

list_of_combinations_prev=[]
for e in lists[0]:
    list_of_combinations_prev.append([e])

for lineno in range(1,number_of_lines_K):
    #print("lineno:",lineno)
    list_of_combinations_current=[]
    for sublist_locp in list_of_combinations_prev:   
        #print("sublist_locp:",sublist_locp)
        for line_data in lists[lineno]:        
            #print("line_data:",line_data)
            list_of_combinations_current.append(sublist_locp+[line_data])
    #print("list_of_combinations_current:",list_of_combinations_current)
    list_of_combinations_prev=list_of_combinations_current

maximized_sum_of_squares=0    
maximized_result=0
for element in list_of_combinations_current[0]:
    maximized_sum_of_squares+=(element*element)
maximized_result = maximized_sum_of_squares%modulo_M

#print(prospective_list)            
prospective_sum_of_squares=0
prospective_result=0

for prospective_list in list_of_combinations_current[1:]:
    prospective_sum_of_squares=0
    for element in prospective_list:
        prospective_sum_of_squares+=(element*element)
    prospective_result=prospective_sum_of_squares%modulo_M
    if prospective_result>maximized_result:
        maximized_result=prospective_result

print(maximized_result,end='')

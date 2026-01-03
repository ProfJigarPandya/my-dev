if __name__ == '__main__':
    N = int(input())
    data_list=[]
    isFirstLine=True
    for step in range(1,N+1):
        line = input().split()
        if line[0] == 'insert': #1
            #insert i e: Insert integer  at position .
            position_i = int(line[1])
            element_e = int(line[2])
            data_list.insert(position_i,element_e)
        elif line[0] == 'print': #2
            #print: Print the list.
            if isFirstLine == True:
                print(data_list,end='')
                isFirstLine = False
            else:
                print('')
                print(data_list,end='')
        elif line[0] == 'remove': #3
            #remove e: Delete the first occurrence of integer
            element_e = int(line[1])
            data_list.remove(element_e)
            pass
        elif line[0] == 'append':#4
            #Insert integer  at the end of the list.
            element_e = int(line[1])
            data_list.append(element_e)
            pass
        elif line[0] == 'sort':#5
            #sort: Sort the list.
            data_list.sort()
            pass
        elif line[0] == 'pop':#6
            #Pop the last element from the list.
            data_list.pop(len(data_list)-1)
            pass
        elif line[0] == 'reverse':#7
            #Reverse the list.
            data_list.reverse()
            pass
        else:
            print(f"Invalid operation {line[0]}") 

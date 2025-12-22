total_integers_N = int(input())
integers_list = list(map(int, input().split()))
#print(total_integers_N)
print(all(datai >= 0 for datai in integers_list) and any(str(dataj) == str(dataj)[::-1] for dataj in integers_list),end="")    

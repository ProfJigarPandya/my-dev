n = int(input())
if n in range(1,21):
	for i in range(0,n-1):
		print(i*i)
	print((i+1)*(i+1),end="")
else:
	print("Input must be between 1 and 20")

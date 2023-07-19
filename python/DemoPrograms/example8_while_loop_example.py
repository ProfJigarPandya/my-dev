# Factorial function:
#    Input:  n
#    Output:  n!
#
def factorial(n):
    if(n<=1):
     return 1

    i=1
    product =1
    while(i<=n):
        product = product * i
        i+=1

    return product

print(factorial(5))

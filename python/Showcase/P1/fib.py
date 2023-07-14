'''
Created on 10-Mar-2016

@author: Jigs
'''
def fib(n):
    a,b=0,1
    while a<n:
        print(a, end=' ')
        a,b=b,a+b
    print()

if __name__ == "__main__":
#print("Hello")
    fib(1000)

"""
if __name__ == "__main__":
    import sys
    fib(int(sys.argv[1]))
"""

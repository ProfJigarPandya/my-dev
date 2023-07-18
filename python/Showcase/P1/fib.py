'''
Created on 10-Mar-2016

@author: Jigs

Fibbonaci series is well known to programmer for learning programming itself in the beginning.


Surprisingly, below answer 

How many bit strings (i.e, sequences over{0,1}) of length 18 have no consecutive ones? (You may write a program to answer this question, although a calculator should also sufﬁce.)

6765, which is 18+3rd 21st term of fibonacci. If first 3 terms are ignored answer to above question can be given via looking at fib result.

I have tried drawing a tree, left branch labelled 0 and right branch labelled 1 and generating path text for all leaves specially avoiding routes where 1 to 1 are back to back. meaning right right following.

Mathametically, 
the logic to count not having consecutive 1's is 
Next term total valids <=  No. of zeroes current * 2 + number of ones current (..logically we will extend only of 0 both left and right and 1's toward zero only)



'''
def fib(n):
    count=1
    a,b=0,1
    while a<n:
        print(count,a)
        a,b=b,a+b
        count=count+1
    print()

if __name__ == "__main__":
#print("Hello")
    fib(6800)

"""
if __name__ == "__main__":
    import sys
    fib(int(sys.argv[1]))
"""

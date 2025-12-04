#!/bin/python3

import math
import os
import random
import re
import sys

#https://docs.python.org/3/reference/compound_stmts.html#if
#https://docs.python.org/3/library/stdtypes.html#range
#i >= 0 and r[i] < stop. by default

if __name__ == '__main__':
    n = int(input().strip())
    
    if n%2!=0:
        print("Weird",end='')
    elif n in range(2,6):
        print("Not Weird",end='')
    elif n in range(6,21):
        print("Weird",end='')
    elif n>20:
        print("Not Weird",end='')   
    else:
        pass

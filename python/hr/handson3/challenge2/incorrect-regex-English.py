'''
If you are using a version of Python older than 3.11, 
using ++ will result in the re.error: multiple repeat mentioned previously 
because the engine does not recognize the possessive syntax (Fails immediately; no backtracking.).
'''
import re
number_of_lines = int(input())
for _ in range(number_of_lines):
    line = raw_input()
    try:
        re.compile(line)
        print(True)
    except Exception:
        print(False)        
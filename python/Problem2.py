'''

Problem2.py
Jigar M. Pandya
jigarpandya.ce@gmail.com

Requirement:

Write a program in Python that reads a file and adds backslash (\) before every double quote it encounters. And then writes it to another file in the same folder.

For example: if the file name is TestFile1.txt with text

ð  Jack said, “Hello Pune”.

The output to the file TestFile2.txt should be

ð  Jack said,\“Hello Pune\”.

Info:
https://docs.python.org/3/howto/regex.html?highlight=regular%20expression
As stated earlier, regular expressions use the backslash character ('\') to indicate special forms or to allow special characters to be used without invoking their special meaning. This conflicts with Python’s usage of the same character for the same purpose in string literals.
In short, to match a literal backslash, one has to write '\\\\' as the RE string, because the regular expression must be \\, and each backslash must be expressed as \\ inside a regular Python string literal. In REs that feature backslashes repeatedly, this leads to lots of repeated backslashes and makes the resulting strings difficult to understand.

'''

import re

def findreplacequote(inputfn, outputfn):
    
    try:

        inf = open(inputfn,'r')
        indata = inf.read()
        inf.close()

        print('Read data from file: ')
        print(indata)


        pattern1 = re.compile('"') #One kind of double quote
        indata = re.sub(pattern1,"\\\\\"", indata)
    
        pattern2 = re.compile('”') #Another kind of double quote start
        indata = re.sub(pattern2,"\\\\”", indata)
    
        pattern2 = re.compile('“') #Another kind of double quote end
        indata = re.sub(pattern2,"\\\\“", indata)

        print('After updating as required: ')
        print (indata)

        outf = open(outputfn,'w')
        outf.write(indata)
        outf.close()

    except FileNotFoundError:
        print('Input file is not found',inputfn)
   

inputfilename = 'TestFile1.txt'
outputfilename = 'TestFile2.txt'

findreplacequote(inputfilename, outputfilename)
print('Have a nice day!')

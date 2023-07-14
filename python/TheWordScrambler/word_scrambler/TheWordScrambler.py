# The Word Scrambler Program Takes input file name and opens the file and scrambles the input file words and writes
# it to other file.

# If you wanna use scrambler module using default inbuilt function following line must be uncomment following line
# and comment next to next line.
from word_scrambler.ScramblerUsingInbuilt import scramble
# from word_scrambler.ScramblerUsingUserDefinedFunction import scramble

# Printing Welcome Message
print("*" * 39)
print("*****Welcome to The Word Scrambler*****")
print("*" * 39)
# Taking input file and trying to read data as well as open output file
file_not_found_flag = True  # Flag variable to keep file ready to be operable
while file_not_found_flag:
    try:
        file_name = str(input("Please enter name of the file consisting of words you want to scramble.\nFile Name:"))
        ip_file = open(file_name, "r")
        data = ip_file.read()
        temp = file_name.partition(".")
        op_file_name = temp[0] + "Scrambled" + temp[1] + temp[2];
        op_file = open(op_file_name, "w")
        file_not_found_flag = False
    except FileNotFoundError:
        print("Input File not Found!!!\nPlease Try Again!")
    except IOError:
        print("Could not read or write into file!!")
        exit(0)
# Splitting file data into individual lines and words and then scrambling individual words
data_lines = data.splitlines()
for i in range(len(data_lines)):
    line = data_lines[i]
    words = line.split(" ")
    s = ""
    for j in range(len(words)):
        s += scramble(words[j]) + " "
    s += "\n"
    op_file.write(s)
# Flushing out not written data and closing input,output file
ip_file.close()
op_file.close()
print("Scrambling Completed Successfully!!!")

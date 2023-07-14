'''
Assume that there is a folder(directory) by name “root”. 
This folder has some files and some subfolders.
Each subfolders in turn may have files and subfolders.
Write a program to lists all the files inside all the folders/subfolders along with their absolute path.
'''
import os.path

def listrecursivedir(src):
    names = os.listdir(src)
    for name in names:
        srcname = os.path.join(src, name)
        if os.path.isdir(srcname):
            listrecursivedir(srcname)
        else:
            print (srcname)

listrecursivedir("C:\TurboC++")

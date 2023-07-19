'''
Created on 28-Dec-2016

@author: CE DDU
'''

from tkinter import Tk, Label, Button

class MyFirstGUI(object):
    '''
    classdocs
    '''


    def __init__(self, root):
        '''
        Constructor
        '''
        self.root = root
        root.title("GUI with titl and label")
        
        self.label = Label(root,text="This is our first GUI")
        self.label.pack()
        
        self.greet_button = Button(root, text="Greet", command=self.greet)
        self.greet_button.pack()
        
    def greet(self):
        print("Greetings!")

root = Tk()
my_gui = MyFirstGUI(root)
root.mainloop()
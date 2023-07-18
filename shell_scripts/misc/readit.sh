#!/bin/bash
# Understanding read

#reads all inputs until enter key into the one and only variable specified
echo "Enter one or more input separated by space, tab. See that read var1 is executed."
read var1
echo $var1 


#reads all inputs into variables specified. If exact input then all variables get values. 
echo "Enter exactly three input separated by space(s) or tab. See that read var1 var2 var3 is executed."
read var1 var2 var3
echo $var1 
echo $var2
echo $var3


#If more number of input are provided than the total variables specified, than last is assigned all remaining input. 
echo "Enter exactly five input separated by space(s) or tab. See that read var1 var2 var3 is executed."
read var1 var2 var3
echo $var1 
echo $var2
echo $var3


#If less number of input than total variables than remaining variables stay unassigned.
echo "Enter exactly three input separated by space(s) or tab. See that read var1 var2 var3 var4 var5 is executed."
read var1 var2 var3 var4 var5
echo $var1 
echo $var2
echo $var3
echo $var4
echo $var5

# Enter your code here. Read input from STDIN. Print output to STDOUT
import calendar
calendar.setfirstweekday(calendar.SUNDAY)
mm,dd,yyyy=input().split()
mm=int(mm)
dd=int(dd)
yyyy=int(yyyy)
#print(mm)
#print(dd)
#print(yyyy)
str=calendar.day_name[calendar.weekday(yyyy,mm,dd)]
print(str.upper(),end='')

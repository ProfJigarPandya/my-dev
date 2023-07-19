# Introduction to if and else if loop

driving_age = 16
smoking_age = 18
lotto_age = 19
drinking_age = 21

age = int(input('How old are you?\n'))

if age >= drinking_age:
    print('You are eligible to drive, smoke, gamble and drink! Please, be careful.')

elif age >= lotto_age:
    print('You are eligible to drive, smoke, gamble! Please, be careful.')

elif age >= smoking_age:
    print('You are eligible to drive and smoke! Please, be careful. ')

elif age >= driving_age:
    print('You are eligible to drive! Please, be careful.')

else:
    print('You can not even drive. Seek assistance!')

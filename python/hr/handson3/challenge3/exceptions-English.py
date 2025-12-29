# Enter your code here. Read input from STDIN. Print output to STDOUT
#https://docs.python.org/2/library/exceptions.html#module-exceptions
number_of_test_cases_T=int(input())
for _ in range(number_of_test_cases_T):
    
    try:
        a,b=map(int,(input().split()))
        result=a//b
    except ZeroDivisionError as e:
        print("Error Code:",e)
        continue
    except ValueError as e:
        print("Error Code:",e,end="")
        continue
    except Exception:
        pass
    else:
        print(result)
    finally:
        pass

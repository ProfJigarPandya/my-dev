def zip(*args):
    """Creates an iterator that aggregates elements from each of the iterables.

    Args:
        *args: Variable length argument list of iterables.  
        for arg in args:
    """
    for arg in args:
        #print(arg)
        while True:
            try:
                yield tuple(next(ite) for ite in arg)
            except StopIteration:
                break

#print("Hello World of python")

students_n,subjects_x=input().split()
#print(students_n)
#print(subjects_x)
subjects_marks=[]
for subject_index in range(int(subjects_x)):
    subject_marks=list(map(float,input().split()))
    subjects_marks.append(iter(subject_marks))


#print(type(zip(subjects_marks)))


zipres=zip(subjects_marks)

for i in range(int(students_n)-1):
    marks=next(zipres)
    result=sum(marks)/len(marks)	
    print(f"{result:.2f}")

marks=next(zipres)
result=sum(marks)/len(marks)	
print(f"{result:.2f}",end='')

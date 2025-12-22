if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    
    query_marks=student_marks[query_name]
    #print(query_marks)
    total_marks=0
    total_subjects=len(query_marks)
    for m in query_marks:
        total_marks+=m
    avegrage_marks = total_marks/total_subjects
    print(f"{avegrage_marks:.2f}",end='')


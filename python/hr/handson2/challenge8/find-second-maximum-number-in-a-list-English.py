from collections import Counter
if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    c=Counter(arr)
    print(sorted(c)[-2])

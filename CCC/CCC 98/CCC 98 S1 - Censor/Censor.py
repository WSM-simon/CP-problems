import sys
input = sys.stdin.readline

N = int(input())
for i in range(N):
    line = input().strip().split()
    for word in line:
        if len(word) == 4:
            print("****",end=' ')
        else:
            print(word, end=' ')
    print()
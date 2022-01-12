import sys

sys.stdin = open(r'C:\Users\Simian\OneDrive\CCC_senior_2021_2\test\test.in', 'r')
N = int(sys.stdin.readline().strip())
cnt = 1

for i in range(N):
    line = sys.stdin.readline().strip()
    for j in range(len(line)-1):
        if line[j] == line[j+1]:
            cnt += 1
        else:
            print(cnt, line[j], end=' ')
            cnt = 1
    print(cnt, line[-1])

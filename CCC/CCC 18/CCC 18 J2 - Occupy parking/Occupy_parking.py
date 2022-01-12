import sys

N = int(sys.stdin.readline())
line1 = sys.stdin.readline().strip()
line2 = sys.stdin.readline().strip()

cont = 0
for i in range(N):
    if line1[i] == line2[i] == 'C':
        cont += 1

print(cont)

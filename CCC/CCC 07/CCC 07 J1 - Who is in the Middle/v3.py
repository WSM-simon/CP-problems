from sys import stdin
r1 = int(stdin.readline())
r2 = int(stdin.readline())
r3 = int(stdin.readline())

print(r1+r2+r2-max(r1,r2,r3)-min(r1,r2,r3))
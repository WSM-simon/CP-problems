import sys
from sys import stdin
from random import randint

t = 1000000
cnt1 = 0
cnt2 = 0
total_A = 0
for i in range(t):
    n = randint(1, 6)
    m = randint(1, 6)

    x = randint(1, 6)
    y = randint(1, 6)

    if (n*m == min(x, y)*min(x, y)):
        cnt1 += 1
    if (n*n == min(x, y)*min(x, y)):
        cnt2 += 1

print(cnt1/t)
print(cnt2/t)
print(cnt2/6/t)

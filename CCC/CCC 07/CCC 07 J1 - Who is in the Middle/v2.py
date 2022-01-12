from sys import stdin
r_in_1 = int(stdin.readline())
r_in_2 = int(stdin.readline())
r_in_3 = int(stdin.readline())

a = max(r_in_1, r_in_2)
b = max(a, r_in_3)

if b == r_in_3:
    print(a)
else:
    print(max(min(r_in_1,r_in_2), r_in_3))


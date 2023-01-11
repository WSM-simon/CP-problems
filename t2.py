ts = set()
l = []
n = int(input())
values = [int(x) for x in input().strip().split()]
for ele in values:
    l.append(ele)
    ts.add(ele)
l.sort()
max = 0
charge = 0
i = 0
for j in range(n):
    if l[i] == l[j]:
        continue
    if (l[i] * (n-1) > max):
        max = l[i] * (n-1)
        charge = l[i]

    i = j

print(max, charge)

from sys import stdin
input = stdin.readline

n = int(input())
data_l = []

for i in range(n):
    rin = input()
    data_l.append(tuple(map(int, rin.split())))

data_l.sort(key=lambda l:l[1])

counter = 1
time_now = data_l[0][1]

for i in data_l:
    if i[0] >= time_now:
        time_now = i[1]
        counter += 1

print(counter)











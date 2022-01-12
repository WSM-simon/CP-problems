speed_limit_list = [0 for i in range(100)]
Bessie_speed_list = [0 for ii in range(100)]

with open('speeding.in', 'r') as fin:
    all_data = fin.read().split('\n')

N, M = map(int, all_data[0].split())

length0 = 0
for i in range(N):
    length1, limit = map(int, all_data[i+1].split())
    for ii in range(length0, length0+length1):
        speed_limit_list[ii] = limit
    length0 += length1

# print(speed_limit_list)
# print('------------------------')


length0 = 0
for i in range(M):
    length1, speed = map(int, all_data[N+i+1].split())
    for ii in range(length0, length0+length1):
        Bessie_speed_list[ii] = speed
        # print(speed, end=' ')
    length0 += length1

# print(Bessie_speed_list)
difference_list = []
for i in range(100):
    difference = Bessie_speed_list[i] - speed_limit_list[i]
    difference_list.append(difference)

max_difference = max(difference_list)
if max_difference < 0:
    max_difference = 0

with open('speeding.out', 'w') as fout:
    fout.write(str(max_difference))
from sys import stdin
input = stdin.readline

l = []
pre_i = ''
while True:
    line = input().strip()
    part_1 = int(line[0]) + int(line[1])
    part_2 = int(line[2] + line[3] + line[4])
    if line == '99999':
        break
    elif (part_1) % 2 == 0 and (part_1) != 0:
        l.append((part_2, 'right'))
        pre_i = 'right'

    elif (part_1) % 2 != 0:
        l.append((part_2, 'left'))
        pre_i = 'left'

    else:
        l.append((part_2, pre_i))

for i in l:
    print(i[1],i[0])

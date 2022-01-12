def find_next_value_position(room_d, position):
    key1 = position[0] * position[1]
    if key1 in room_d:
        position_list = room_d[key1]
        del room_d[key1]
        return position_list
    else:
        return None


go = True
answer = False
def isEscapeable(room_d, t):
    global go, answer
    if go:
        next_p_l = find_next_value_position(room_d, t)
        if next_p_l == None:
            return False
        elif (1, 1) in next_p_l:
            go = False
            return True
        else:
            for p in next_p_l:
                answer =  isEscapeable(room_d, p)
    return answer


###############################################################################
from sys import stdin, setrecursionlimit

setrecursionlimit(10**6)

all_data = stdin.read().strip().split('\n')

rows = int(all_data[0])
columns = int(all_data[1])

room = []
room_dict = {}

for i in range(rows):
    x = list(map(int, all_data[i+2].split()))
    room.append(x)

for i in range(columns):
    for ii in range(rows):
        if room[ii][i] in room_dict:
            room_dict[room[ii][i]].append((ii+1, i+1))
        else:
            room_dict[room[ii][i]] = [(ii+1, i+1)]

del room

position = (rows, columns)

if isEscapeable(room_dict, position):
    print('yes')
else:
    print('no')
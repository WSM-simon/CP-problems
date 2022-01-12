from itertools import permutations
from copy import deepcopy

fin = open('art.in', 'r')
fout = open('art.out', 'w')

all_data = fin.read().split('\n')
n = int(all_data[0])

canvas = [list(map(int, list(all_data[i+1]))) for i in range(n)]
number_set = {canvas[i][ii] for i in range(n) for ii in range(n)}
number_set.discard(0)
number_list = list(number_set)
del number_set

lens = len(number_list)

def count_rectangle(list1, num):
    width_l = []
    length_l = []
    y_p = 0
    x_list = []
    for i in range(len(list1)):
        if num in list1[i]:
            if y_p == 0:
                y_p = i
            width_l.append(len(list1) - sorted(list1[i], reverse=True).index(num) - list1[i].index(num))
            length_l.append(i)
            x_list.append(list1[i].index(num))
            print(x_list)

    position = (max(x_list), y_p)
    print(length_l)
    print(width_l)

    return position, max(length_l)-min(length_l)+1, max(width_l)


def draw_numbers(list2D, t_data, n):    #t_data 是 number_area_dict 的一个值
    first_x, first_y  = t_data[0][1], t_data[0][0]
    list2D[first_y][first_x] = n
    for i in range(t_data[1]):
        for ii in range(t_data[2]):
            list2D[first_y+i][first_x+ii] = n

number_area_dict = {}
for i in range(lens):
    number_area_dict[(number_list[i])] = count_rectangle(canvas, number_list[i])


test_l = [[0 for i in range(n)] for ii in range(n)]

counter = 0
orders = list(permutations(number_list, lens))


for i in orders:
    l = deepcopy(test_l)
    for ii in i:
        draw_numbers(l, number_area_dict[ii], ii)
    if l == canvas:
        counter += 1
    print(l)

fout.write(str(counter))

fin.close()
fout.close()









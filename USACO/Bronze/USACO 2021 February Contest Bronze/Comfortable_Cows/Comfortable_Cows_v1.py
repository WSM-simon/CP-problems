def up_value_change(table, x, y):
# 点上方comfortable值变动
        table[x][y - 1] += 1

def down_value_change(table, x, y):
# 点下方comfortable值变动
        table[x][y + 1] += 1

def left_value_change(table, x, y):
# 点左方comfortable值变动
        table[x - 1][y] += 1

def right_value_change(table, x, y):
  # 点右方comfortable值变动
        table[x + 1][y] += 1

def add_comfortable_vaule(table, x, y, g_sidelength):
    table[x][y] += 10       # 自己点加2
    if x != 0:  # 贴左边
        left_value_change(table, x, y)
    if x != g_sidelength-1:  # 贴右边
        right_value_change(table, x, y)
    if y != 0:  # 贴上边
        up_value_change(table, x, y)
    if y != g_sidelength-1:  # 贴下边
        down_value_change(table, x, y)


def comfortable_value_detect(table, x, y, g_sidelength):
    counter_in = 0
    detection_object = []
    detection_object.append(table[x][y])
    if x != 0:
        detection_object.append(table[x-1][y])
    if x != g_sidelength - 1:
        detection_object.append(table[x+1][y])
    if y != 0:
        detection_object.append(table[x][y-1])
    if y != g_sidelength - 1:
        detection_object.append(table[x][y+1])


    for i in detection_object:
        if i == 13:
            counter_in += 1
        if i == 14:
            counter_in -= 1

    return counter_in

#########################################

g_sidelength = 1000
comfortable_table = [[0 for i in range(g_sidelength)] for j in range(g_sidelength)] # 2D list
counter = 0
counter_list = []

number_of_cows = int(input())
for ii in range(number_of_cows):
    cow_position = input().strip().split()
    y = int(cow_position[0])
    x = int(cow_position[1])
    add_comfortable_vaule(comfortable_table, x, y, g_sidelength)
    counter += comfortable_value_detect(comfortable_table, x, y, g_sidelength)
    counter_list.append(str(counter))


for iii in counter_list:
    print(iii)

#print(f'{comfortable_table[9]}\n{comfortable_table[8]}\n{comfortable_table[7]}\n{comfortable_table[6]}\n{comfortable_table[5]}\n{comfortable_table[4]}\n{comfortable_table[3]}\n{comfortable_table[2]}\n{comfortable_table[1]}\n{comfortable_table[0]}\n')
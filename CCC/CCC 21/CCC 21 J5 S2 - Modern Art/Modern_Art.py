import sys

def brush_checkerboard_column():
    number_of_god_pattern1 = 0
    for k, v in action_on_column.items():
        if v % 2 == 0:
            continue
        else:
            for j in range(column):
                checkerboard[j][k-1] *= -1
                if checkerboard[j][k-1] == 1:
                    number_of_god_pattern1 += 1
                else:
                    number_of_god_pattern1 -= 1

    return number_of_god_pattern1

def brush_checkerboard_row():
    number_of_god_pattern2 =0
    for k, v in action_on_row.items():
        if v % 2 == 0:
            continue
        else:
            for i in range(row):
                checkerboard[k-1][i] *= -1
                if checkerboard[k-1][i] == 1:
                    number_of_god_pattern2 += 1
                else:
                    number_of_god_pattern2 -= 1

    return number_of_god_pattern2

###################################################################
all_data = sys.stdin.read().split('\n')

column = int(all_data[0])
row = int(all_data[1])
number_choices = int(all_data[2])

checkerboard = [[-1 for i in range(row)] for ii in range(column)]
action_on_row = {}
action_on_column = {}

for iii in range(number_choices):
    choice = list(all_data[iii+3])
    if choice[0] == 'R':
        if int(choice[1]) not in action_on_row:
            action_on_row[int(choice[1])] = 1
        else:
            action_on_row[int(choice[1])] += 1

    if choice[0] == 'C':
        if int(choice[1]) not in action_on_column:
            action_on_column[int(choice[1])] = 1
        else:
            action_on_column[int(choice[1])] += 1

number_of_god_pattern = 0
number_of_god_pattern += brush_checkerboard_row()
number_of_god_pattern += brush_checkerboard_column()

print(number_of_god_pattern)

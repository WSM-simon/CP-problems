def get_cows_number():
    with open("8.in", "rt") as in_file:
        text = in_file.readline()
        l1 = text.split()
        return int(l1[0])

def get_data_create_2D_arrary(data_lines):
    with open("8.in", "rt") as in_file:  # open file to read data
        text = in_file.readline()  ## jump over the first line
        for iii in range(data_lines):  # read several lines from input file.
            text = in_file.readline()
            l1 = text.split()       ## make the string (text) into LIST structure
            if len(l1) == 2:
                i_x, i_y = int(l1[0]), int(l1[1])
                #print(i_x, '  ', i_y)
                list_2D[i_y][i_x] = 1

    return

###############################################################################
if __name__ == '__main__':
    ############## global value ####################
    list1 = []
    x, y = 1000, 1000
    list_2D = [[0 for i in range(x)] for j in range(y)]  # list2D[y][x]
    ################################################
    cows_number = get_cows_number()

    for iiii in range(1,cows_number+1):
        get_data_create_2D_arrary(iiii)   # refresh list_2D
        comfortable_cows = 0

        for j in range(y):
            for i in range(x):
                comfortable_criteria = 0
                if i > 0:
                    if list_2D[j][i-1] == 1 and list_2D[j][i] ==1 :
                        comfortable_criteria += 1
                if i < x-1:
                    if list_2D[j][i+1] == 1  and list_2D[j][i] ==1 :
                        comfortable_criteria += 1
                if j > 0:
                    if list_2D[j-1][i] == 1 and list_2D[j][i] ==1 :
                        comfortable_criteria += 1
                if j < y-1:
                    if list_2D[j+1][i] == 1 and list_2D[j][i] ==1 :
                        comfortable_criteria += 1
                if comfortable_criteria == 3:
                    comfortable_cows += 1

        #print('There are %d comfortable cows.'%comfortable_cows)
        #print(f'In the No.{iiii} step, there are {comfortable_cows} comfortable cows.')
        list1.append(comfortable_cows)

    '''for jjjj in range(y):
        print(list_2D[y-1-jjjj])'''
    for i in list1:
        print(i)
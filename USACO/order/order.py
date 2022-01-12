
def sort_funtion(list_input, reverse=True):
    if not reverse:
        turn = 0
        for k in range(len(list_input)):
            i = -1
            while True:
                i += 1
                if i == len(list_input) - 1 - turn:
                    break
                if ord(list_input[i]) > ord(list_input[i+1]):
                    list_input[i], list_input[i+1] = list_input[i+1], list_input[i]
            turn += 1
    else:
        turn = 0
        for k in range(len(list_input)):
            i = 0
            while True:
                i -= 1
                if i == -len(list_input) + turn:
                    break
                if ord(list_input[i]) > ord(list_input[i-1]):
                    list_input[i], list_input[i-1] = list_input[i-1], list_input[i]
            turn += 1

    return list_input


list1 = list(input().strip())
print(sort_funtion(list1, reverse=True))
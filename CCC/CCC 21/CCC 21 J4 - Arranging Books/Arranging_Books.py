import sys

unarranged_books = sys.stdin.readline().strip()

swap_step = 0

number_of_L = unarranged_books.count("L")
number_of_M = unarranged_books.count("M")
number_of_S = len(unarranged_books)-number_of_L-number_of_M


part_L = unarranged_books[:number_of_L]
part_M = unarranged_books[number_of_L:number_of_L+number_of_M]
part_S = unarranged_books[number_of_L+number_of_M:]

M_in_L_part = 0
S_in_L_part = 0
M_in_S_part = 0
L_in_S_part = 0
S_in_M_part = 0
L_in_M_part = 0


for j in part_L:
    if j == 'M':
        M_in_L_part += 1
    elif j == 'S':
        S_in_L_part += 1

for j in part_M:
    if j == 'L':
        L_in_M_part += 1
    elif j == 'S':
        S_in_M_part += 1

for j in part_S:
    if j == 'L':
        L_in_S_part += 1
    elif j == 'M':
        M_in_S_part += 1

high_efficiency_swap_step = min(M_in_L_part, L_in_M_part) + min(L_in_S_part, S_in_L_part) + min(M_in_S_part, S_in_M_part)

number_of_wrong = abs(M_in_L_part - L_in_M_part)
low_efficiency_swap_step = number_of_wrong * 2

swap_step = high_efficiency_swap_step + low_efficiency_swap_step
print(swap_step)

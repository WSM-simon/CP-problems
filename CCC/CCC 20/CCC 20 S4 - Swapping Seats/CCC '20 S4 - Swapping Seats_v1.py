from sys import stdin,exit
from collections import Counter,deque

def arrange_people(counter_A, counter_B, counter_C = None):
    low_effective_swap = min(counter_A['B'],counter_B['A'])
    if counter_C != None:
        low_effective_swap += min(counter_B['C'], counter_C['B']) + min(counter_A['C'], counter_C['A'])
    high_effective_swap = 2 * abs(counter_A['B'] - counter_B['A'])

    swap_step = low_effective_swap + high_effective_swap
    return swap_step


unarranged_peoples = stdin.readline().strip()
lens = len(unarranged_peoples)

n_A = unarranged_peoples.count('A')
n_B = unarranged_peoples.count('B')
n_C = unarranged_peoples.count('C')

if n_B == 0:
    print('0')
    exit()

group_A = unarranged_peoples[:n_A]
group_B1 = unarranged_peoples[n_A:n_A + n_B]

counter_A = Counter(group_A)
counter_B1 = Counter(group_B1)

if n_C != 0:
    group_C1 = unarranged_peoples[n_A + n_B:]

    group_C2 = unarranged_peoples[n_A:n_A + n_C]
    group_B2 = unarranged_peoples[n_A + n_C:]

    counter_C1 = Counter(group_C1)

    counter_B2 = Counter(group_B2)
    counter_C2 = Counter(group_C2)

less_swap = -1
deque_u_p = deque(unarranged_peoples)

for i in range(lens):
    cg1 = deque_u_p[0]
    cg2 = deque_u_p[n_A]


    counter_A[cg1] -= 1
    counter_A[cg2] += 1


    if n_C == 0:
        counter_B1[cg2] -= 1
        counter_B1[cg1] += 1
        swap_step0 = arrange_people(counter_A, counter_B1)

        if less_swap == -1:
            less_swap = swap_step0
        elif swap_step0 < less_swap:
            less_swap = swap_step0

    elif n_C != 0:
        cg3 = deque_u_p[n_A + n_B]
        cg4 = deque_u_p[n_A + n_C]

        counter_B1[cg2] -= 1
        counter_B1[cg3] += 1

        counter_C1[cg3] -= 1
        counter_C1[cg1] += 1

        counter_C2[cg2] -= 1
        counter_C2[cg4] += 1
        counter_B2[cg4] -= 1
        counter_B2[cg1] += 1

        swap_step1 = arrange_people(counter_A, counter_B1, counter_C1)
        if less_swap == -1:
            less_swap = swap_step1
        elif swap_step1 < less_swap:
            less_swap = swap_step1

        swap_step2 = arrange_people(counter_A, counter_B2, counter_C2)
        if swap_step2 < less_swap:
            less_swap = swap_step2

    deque_u_p.append(deque_u_p.popleft())

print(less_swap)
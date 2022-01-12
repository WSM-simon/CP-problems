from sys import stdin, exit
from collections import Counter

def arrange_2_kinds_people(A_in_B, B_in_A):
    if A_in_B > B_in_A:
        swap_step = 3 * A_in_B - 2 * B_in_A
    else:
        swap_step = 3 * B_in_A - 2 * A_in_B

    return swap_step

def arrange_3_kinds_people(B_in_A, C_in_B, B_in_C, C_in_A):
    # low_effective_swap = min(A_in_B, B_in_A) + min(B_in_C, C_in_B) + min(A_in_C, C_in_A)
    # high_effective_swap = 2 * abs(A_in_B - B_in_A)
    #
    # swap_step = low_effective_swap + high_effective_swap
    swap_step = B_in_A + C_in_A + max(C_in_B, B_in_C)
    return swap_step

u_p = unarranged_peoples = stdin.readline().strip()

lens = len(unarranged_peoples)

count_u_p = Counter(u_p)
type = len(count_u_p)
less_swap = -1

if type == 1:
    print('0')
    exit()

elif type == 2:
    tuple_of_type = tuple(count_u_p.keys())
    tuple_of_type_values = tuple(count_u_p.values())

    e_1 = tuple_of_type[0]
    e_2 = tuple_of_type[1]
    e_1_v = tuple_of_type_values[0]

    group_1 = u_p[:e_1_v]
    group_2 = u_p[e_1_v:]

    counter_1 = Counter(group_1)     #count groupA
    counter_2 = Counter(group_2)  #count groupB

    for i in range(lens):
        cg1 = u_p[i]
        cg2 = u_p[(i+e_1_v)%lens]

        counter_1[cg1] -= 1
        counter_1[cg2] += 1
        counter_2[cg2] -= 1
        counter_2[cg1] += 1

        _1_in_2 = counter_2[e_1]
        _2_in_1 = counter_1[e_2]

        swap_step1 = arrange_2_kinds_people(_1_in_2, _2_in_1)

        if swap_step1 == 0:
            less_swap = swap_step1
            break

        elif less_swap == -1:
            less_swap = swap_step1

        elif swap_step1 < less_swap:
            less_swap = swap_step1

else:
    n_A = count_u_p['A']
    n_B = count_u_p['B']
    n_C = count_u_p['C']

    group_A = u_p[:n_A]
    group_B1 = u_p[n_A:n_A+n_B]
    group_C1 = u_p[n_A+n_B:]

    group_C2 = u_p[n_A:n_A+n_C]
    group_B2 = u_p[n_A+n_C:]

    counter_A = Counter(group_A)
    counter_B1 = Counter(group_B1)
    counter_C1 = Counter(group_C1)

    counter_B2 = Counter(group_B2)
    counter_C2 = Counter(group_C2)

    for i in range(lens):
        cg1 = u_p[i]
        cg2 = u_p[(i+n_A)%lens]
        cg3 = u_p[(i+n_A+n_B)%lens]
        cg32 = u_p[(i+n_A+n_C)%lens]

        counter_A[cg1] -= 1
        counter_A[cg2] += 1
        counter_B1[cg2] -= 1
        counter_B1[cg3] += 1
        counter_C1[cg1] += 1
        counter_C1[cg3] -= 1

        counter_C2[cg2] -= 1
        counter_C2[cg32] += 1
        counter_B2[cg32] -= 1
        counter_B2[cg1] += 1


        B_in_A = counter_A['B']
        C_in_B1 = counter_B1['C']
        B_in_C1 = counter_C1['B']
        C_in_A = counter_A['C']
        C_in_B2 = counter_B2['C']
        B_in_C2 = counter_C2['B']

        swap_step2 = arrange_3_kinds_people(B_in_A, C_in_B1, B_in_C1, C_in_A)
        swap_step3 = arrange_3_kinds_people(B_in_A, C_in_B2, B_in_C2, C_in_A)

        swap_step_min23 = min(swap_step2,swap_step3)

        if swap_step_min23 == 0:
            less_swap = swap_step_min23
            break

        elif less_swap == -1:
            less_swap = swap_step_min23

        elif swap_step_min23 < less_swap:
            less_swap = swap_step_min23

print(less_swap)
from sys import stdin
unarranged_peoples = stdin.readline().strip()

n_L = unarranged_peoples.count('L')
n_M = unarranged_peoples.count('M')

group_L = unarranged_peoples[:n_L]
group_M = unarranged_peoples[n_L:n_M+n_L]
group_S = unarranged_peoples[n_M+n_L:]

M_in_L = group_L.count('M')
S_in_L = group_L.count('S')
L_in_M = group_M.count('L')
S_in_M = group_M.count('S')
L_in_S = group_S.count('L')
M_in_S = group_S.count('M')

low_effective_swap = min(M_in_L,L_in_M) + min(L_in_S, S_in_L) + min(M_in_S, S_in_M)
high_effective_swap = 2 * abs(L_in_M - M_in_L)

swap_step = low_effective_swap + high_effective_swap
print(swap_step)







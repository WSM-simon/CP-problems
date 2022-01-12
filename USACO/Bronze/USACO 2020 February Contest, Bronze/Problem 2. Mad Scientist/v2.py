import sys
sys.stdin = open("breedflip.in","r")
sys.stdout = open("breedflip.out","w")

N,a,b = input(),input(),input()
s = [False]+[x != y for x,y in zip(a,b)] # difference list
# now count occurrences of [False,True], as the first C++ solution does
print(sum(1 if not x and y else 0 for x,y in zip(s,s[1:])))

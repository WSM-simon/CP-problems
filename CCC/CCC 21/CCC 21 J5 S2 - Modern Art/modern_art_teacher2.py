from sys import stdin


all_data = stdin.read().split('\n')

m = int(all_data[0].strip())
n = int(all_data[1].strip())
k = int(all_data[2].strip())

# read all painting choices
choices = {}
for i in range(k):
    if all_data[i+3] in choices:
        del choices[all_data[i+3]]
    else:
        choices[all_data[i+3]] = 1
# counts of rows and columns was painted in odd times
r = 0
c = 0
for item in choices:
    if item[0] == "R":
        r += 1
    elif item[0] == "C":
        c += 1

# calculate the result
result = r*n + c*m - 2*r*c

print(result)
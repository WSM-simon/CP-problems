import sys

all_data = sys.stdin.read().split('\n')

m = int(all_data[0].strip())
n = int(all_data[1].strip())
k = int(all_data[2].strip())

# read all painting choices
choices = {'R':0, 'C':0}
for i in range(k):
    if all_data[i+3] in choices:
        del choices[all_data[i+3]]
        choices[all_data[i+3][0]] -= 1
    else:
        choices[all_data[i+3]] = None
        choices[all_data[i+3][0]] += 1

# counts of rows and columns was painted in odd times
r = choices['R']
c = choices['C']


# calculate the result
result = r*n + c*m - 2*r*c

print(result)
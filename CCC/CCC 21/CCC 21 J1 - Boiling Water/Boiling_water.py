b = int(input().strip())
p = 5*b-400

s = 0
if p > 100:
    s = -1
elif p < 100:
    s = 1

print(p)
print(s)



import sys

datas = sys.stdin.readlines()

for data in datas:
    words = data.split()
    words = words[::-1]
    out = []
    for word in words:
        if not word.isnumeric():
            out.append(word[::-1])
            continue
        out.append(word)
    print(" ".join(out))



import sys

flips = sys.stdin.readline().strip()
num_H = flips.count("H")

do_H = num_H % 2 != 0
do_V = (len(flips)-num_H) % 2 != 0

if do_H and do_V:
    print("4 3\n2 1")
elif do_H:
    print("3 4\n1 2")
elif do_V:
    print("2 1\n4 3")
else:
    print("1 2\n3 4")


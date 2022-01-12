import sys
from collections import defaultdict

# sys.stdin = open(r'C:\Users\wangs\Desktop\python_2021_2\test.in', 'r')
sys.stdin = open('gates.in', 'r')
sys.stdout = open('gates.out', 'w')

n = int(sys.stdin.readline())
route = sys.stdin.readline()

vertex = set()
edge = set()




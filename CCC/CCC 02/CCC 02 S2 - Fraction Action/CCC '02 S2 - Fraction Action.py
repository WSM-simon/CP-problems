import sys
from fractions import Fraction
n = int(sys.stdin.readline().strip())
d = int(sys.stdin.readline().strip())

p_1 = n // d
p_2 = n - p_1*d
if p_2:
    f = Fraction(p_2,d)
    print(f'{p_1} {f.numerator}/{f.denominator}')
else:
    print(f'{p_1}')


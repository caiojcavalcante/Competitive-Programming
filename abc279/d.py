import math

def solve(x, a, b):
    return a / pow(x, 1 / 2) + b * (x - 1)

a, b = input().split(' ')

a = int(a)
b = int(b)

x = math.ceil(pow(2 * b / a, -2 / 3))
y = x - 1
print("%.10lf" % min(solve(x, a, b), solve(y, a, b)))

n = int(input())
s = input() + 'c'
a = 0

total = 0

for i in range(n):
    if (s[i] == 'a' and s[i + 1] == 'a'):
        total += 1
        a = 1
    elif (a == 1):
        a = 0
        total += 1

print(total)
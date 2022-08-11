import sys
import math

n = int(input())
mah = 0
yu = 0
ch = 0
x = list(map(int, input().split()))
for i in range(n):
    mah += abs(x[i])
    yu += x[i]*x[i]
    if abs(x[i]) >= ch:
        ch = abs(x[i])


print(mah)
print(math.sqrt(yu))
print(ch)
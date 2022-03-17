
#파이썬으로 연결하는 거 배워야 돼!
from math import factorial
n, k = map(int, input().split())
b = factorial(n) // (factorial(k) * factorial(n - k))
print(b)
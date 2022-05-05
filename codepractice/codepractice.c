
#파이썬으로 연결하는 거 배워야 돼!
from math import factorial
n, k = map(int, input().split())
b = factorial(n) // (factorial(k) * factorial(n - k))
print(b)

a, b = map(int, input().split())
c = list(map(int, input().split()))

for i in c :
if i < b :
    print(i, end = " ")
    잘살고싶다 성공하고싶다

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
  


#220531
import sys
input = sys.stdin.readline

n, k = map(int, input().split())
lst = list(map(int, input().split()))

cnt = 0
start, end = 0, 0
size, size_max = 0, 0
flag = 1

for start in range(n) :
    while cnt <= k and flag :
        if lst[end] % 2 :
            if cnt == k :
                break
                cnt += 1
                size += 1
                if end == n - 1 :
                    flag = 0
                    break
                    end += 1

                    if size_max < size - cnt :
                        size_max = size - cnt

                        if lst[start] % 2 :
                            cnt -= 1

                            size -= 1

                            print(size_max)





#220601
n = int(input())
k = int(input())
sensor = list(map(int, input().split()))
sensor.sort()
btwss = [sensor[i] - sensor[i - 1] for i in range(1, n)]
btwss.sort()

if k >= n : print(0)
else : #k < n
    for i in range(k - 1) :
        btwss.pop()
        print(sum(btwss))


#220602
from collections import deque
import sys

def bfs(node) :
    q = deque()
        q.append(node)
        check[node] = 0
        while q :  ssssssss
            node = q.popleft()
            d = [node - 1, node + 1]
            if graph[node] :
                d += graph[node]
                for n in d :
if (1 <= n <= N) and check[n] == -1 :
    q.append(n)
    check[n] = check[node] + 1
    if n == E :
        return check[n]

        N, M = map(int, sys.stdin.readline().split())
        S, E = map(int, sys.stdin.readline().split())
        graph = [[]for _ in range(N + 1)]
        check = [-1] * (N + 1)
        for _ in range(M) :
            u, v = map(int, sys.stdin.readline().split())
            graph[u].append(v)
            graph[v].append(u)
            cnt = bfs(S)

#
            N = int(input())
            li = list(map(int, input().split()))
            k = cnt = 0
            for i in range(li.index(0), N) :
                if li[i] == k :
                    k = (k + 1) % 3
                    cnt += 1
                    print(cnt)
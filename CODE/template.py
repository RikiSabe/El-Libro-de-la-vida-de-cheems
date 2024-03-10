from math import gcd

def solve():
    n,k = map(int,input().split())
    acum = 0
    for i in range(1,n+1):
        acum = acum + (i // gcd(i, 2 **k))
    print(acum)

n = int(input())
for _ in range(n):
    solve()
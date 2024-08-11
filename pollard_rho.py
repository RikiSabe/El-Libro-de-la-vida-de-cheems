from collections import Counter
from random import randrange
from math import gcd

def miller_rabin_test(n):
    if n < 2 or not n % 2 or not n % 3:
        return n in (2, 3)   
    k, r, d = 5, 0, n - 1
    while d % 2 == 0: 
        d //= 2
        r += 1
    while k >= 1:
        k -= 1
        a = randrange(2, n - 1)
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            continue
        m = r - 1
        while m >= 1:
            m -= 1
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else: 
            return False
    return True
    
def is_prime(n):
    return miller_rabin_test(n)

def pollard_rho(n):
    while True:
        x, c = randrange(1, n), randrange(1, n)
        f = lambda x: (x * x + c) % n
        y = f(x)
        while (d := gcd(abs(x - y), n)) == 1:
            x, y = f(x), f(f(y))
        if d != n:
            return d

def factor(n):
    if is_prime(n): return Counter([n])
    return factor(r := pollard_rho(n)) + factor(n // r)

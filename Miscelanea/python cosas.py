// eval
x = 1
print(eval('x + 1'))

import random
cadena_aleatoria = ''.join(random.choices('123456789', k=100))

// operaciones con fechas
from datetime import datetime
def dias_transcurridos(d, m):
    fecha_inicial = datetime(2021, 1, 1)
	  fecha_dada = datetime(2021, m, d)
    diferencia = fecha_dada - fecha_inicial
    print(diferencia.days)


// replace
txt = "I like bananas"
x = txt.replace("bananas", "apples")
print(x)

// replace con recursion
import re
s = "bananas"
ss = re.sub(r"bananas", "apples", s)
print(ss)
// para eliminar espacios innecesarios
ss = re.sub(r'\s+', ' ', s)
print(ss)

// fast input
import sys
input = sys.stdin.readline


// precision en digitos: 
from decimal import Decimal, getcontext, ROUND_UP

a, b, k = input().split()
k = int(k)
getcontext().prec = k + 10
a = Decimal(a)
b = Decimal(b)
resultado = a / b
quantize_format = Decimal('1.' + '0' * k)
redondeado = resultado.quantize(quantize_format, rounding=ROUND_UP)
print(redondeado)


from decimal import *
getcontext().prec = 100
// getcontext().rounding() = ROUND_UP
s = Decimal(2).sqrt()
print(s)

import bisect
index = biset.bisect_left(s,num) # lista, numero, LOWERBOUND

import itertools
from collections import defaultdict
A = ['a', 'b', 'c']
permu = list(itertools.permutation(A))


from sortedcontainers import SortedList

sl = SortedList([1, 3, 3, 5, 7, 9])

index_left = sl.bisect_left(3)
index_right = sl.bisect_right(3)

sl.add(3)  # Insertar un nuevo 3
print(sl)  # Salida: SortedList([1, 3, 3, 3, 5, 7, 9])
try:
    sl.remove(10)
except ValueError:
    print("No se puede eliminar 10 porque no está en la lista.")

if elemento_a_buscar in sl:
    print(f"{elemento_a_buscar} existe en la lista.")

// binario sin zeros a la izquierda
binario = bin(x)[2:]

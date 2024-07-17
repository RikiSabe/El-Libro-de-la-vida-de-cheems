// eval
x = 1
print(eval('x + 1'))


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

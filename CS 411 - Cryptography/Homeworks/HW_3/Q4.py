from myntl import *
import math
from sympy.ntheory.primetest import is_square

N = 15220196297956469159
C = 6092243189299681137
e = pow(2, 16)+1


a = math.isqrt(N) + 1

while True:
    b2 = pow(a, 2) - N
    
    if is_square(b2):
        b = math.sqrt(b2)
        break
    a += 1

p = a - b
q = a + b

phi_n = (p-1) * (q-1)

d = modinv(e, phi_n)
print(d)

# Calculating C^d mod N
message = (C**d) % N
print(message)
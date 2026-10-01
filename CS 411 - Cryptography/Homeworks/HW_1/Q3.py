# Emir Asal 27933 - CS 411 HW01 - Question 3

from hw01_helper import phi

dict = {'A':0, 'B':1, 'C':2, 'D':3, 'E':4, 'F':5, 'G':6, 'H':7,
 'I':8, 'J':9, 'K':10, 'L':11, 'M':12, 'N':13, 'O':14, 'P':15,
  'Q':16, 'R':17, 'S':18, 'T':19, 'U':20,
 'V':21, 'W':22, 'X':23, 'Y':24, 'Z':25, '.':26, ' ':27}


new_affine = {}
for n in dict:
    for m in dict:
        new_affine[n + m]= dict.get(n) * 28 + dict.get(m)

mod = len(new_affine)
print("Size of modulus: ", mod)

# beta can take any value
beta_amount = mod

# alpha can take:
alpha_amount = phi(mod)
key_space = alpha_amount * beta_amount

print("Size of the key space is:", key_space)

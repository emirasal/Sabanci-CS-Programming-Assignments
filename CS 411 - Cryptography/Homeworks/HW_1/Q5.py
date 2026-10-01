# Emir Asal 27933 - CS 411 HW01 - Question 5

import math
from Q3 import new_affine, mod
from hw01_helper import modinv

cipher = "ZDZUKEO.AANDOGIJTLNEKEPHZUQDX NDS VLNDJGQLYDVSBU.DER.K.UYT"
# Reversing my new dictionary I created in Question 3
inv_new_affine = {v: k for k, v in new_affine.items()}


alpha_values = []
for i in range(1, mod+1):
    if math.gcd(i, mod) == 1:
        alpha_values.append(i)


# .X turned into YT
last_2_plain = new_affine.get('.X')
last_2_cipher = new_affine.get('YT')

key_possibilities = []
for a in alpha_values:
    beta = (last_2_cipher - (a * last_2_plain))%mod
    key_possibilities.append([a, beta])

# We need to customize the given Dec Function
def Biagram_Affine_Dec(ptext, key):
    plen = len(ptext)
    ctext = ''
    for i in range (0,plen,2):
        letter = ptext[i] + ptext[i+1]
        if letter in new_affine:
            poz = new_affine[letter]
            poz = (key.gamma*poz+key.theta)%mod
            #print poz
            ctext += inv_new_affine[poz]
        else:
            ctext += ptext[i] + ptext[i+1]
    return ctext

class key(object):
    alpha=0
    beta=0
    gamma=0
    theta=0


# Try possible keys
for k in key_possibilities:
    key.alpha = k[0]
    key.beta = k[1]
    key.gamma = modinv(key.alpha, mod) # you can compute decryption key from encryption key
    key.theta = mod-(key.gamma*key.beta)%mod
    print("Plain Text: ", Biagram_Affine_Dec(cipher, key), "   Corresponding Key is: [", key.alpha, key.beta, "]")

# Plain Text is "I HAVE COME TO BELIEVE THAT THE WHOLE WORLD IS AN ENIGMA.X"  Corresponding Key is: [ 185 524 ]
plain_text = "I HAVE COME TO BELIEVE THAT THE WHOLE WORLD IS AN ENIGMA."
correct_key = [185, 524]

print("Correct key is ", correct_key)
print("Correct plain text is:", plain_text)




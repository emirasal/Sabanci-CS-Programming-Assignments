# Emir Asal 27933 - CS 411 HW01 - Question 2 

from hw01_helper import modinv , Affine_Dec
from hw01_helper import uppercase, letter_count
import math

# plain most frequent = T
def count_letters(text):
    for char in text:
        if char in uppercase:
            letter_count[char] += 1

cipher = "ZJOWMJ ZJGC BS UEVRSCC, KSZ ZJSFS GC USZJOV GR GZ."
count_letters(cipher)
print("Most Frequent two letters are S and Z")

alpha = []
# T has been encrtypted as S or Z 
for i in range(1, 27):
    if math.gcd(i, 26) == 1:
        alpha.append(i)

possible_keys = []
for a in alpha:
    # For S
    beta = (uppercase.get('S') - (a * uppercase.get('T')))%26
    possible_keys.append([a, beta])
    # For Z
    beta = (uppercase.get('Z') - (a * uppercase.get('T')))%26
    possible_keys.append([a, beta])
print("Possible Keys are:", possible_keys)


class key(object):
    alpha=0
    beta=0
    gamma=0
    theta=0



# Descrypting for every key
for k in possible_keys:
    key.alpha = k[0]
    key.beta = k[1]
    key.gamma = modinv(key.alpha, 26) # you can compute decryption key from encryption key
    key.theta = 26-(key.gamma*key.beta)%26
    print(Affine_Dec(cipher, key), "Corresponding key is:", "[", key.alpha, key.beta, "]")


# Meaningful sentence is "THOUGH THIS BE MADNESS, YET THERE IS METHOD IN IT."
# We have found the correct key! [23, 4]
key.alpha = 23
key.beta = 4
key.gamma = modinv(key.alpha, 26)
key.theta = 26-(key.gamma*key.beta)%26
plain_text = Affine_Dec(cipher, key)
print("")
print("Correct Plain Text is:", plain_text)
print("Correct Key is:", "[23, 4]")
print("Alpha:", key.alpha, "Beta:", key.beta, "Gamma:", key.gamma, "Theta:", key.theta)
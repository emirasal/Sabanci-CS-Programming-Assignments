# Emir Asal 27933 - CS 411 HW01 - Question 6

import random

def xor (b1, b2):
    if b1 == b2: return "0"
    else: return "1"

def calculate_frequency (binary_text, letter):
    count = 0
    for char in binary_text:
        if char == letter:
            count += 1

    return count/len(binary_text)

plain_text = "ŞİFRELENECEKBİRMESAJ"

plain_text_bit_represantation = ''.join(format(ord(i), '08b') for i in plain_text)

key = ""
#Creating random key
for i in range (0,len(plain_text_bit_represantation)):
    key += str(random.randint(0,1))

cipher = ""
for i in range(0, len(key)):
    cipher += xor(plain_text_bit_represantation[i], key[i])

print("Plain Text: ", plain_text_bit_represantation)
print("Random Generated Key: ", key)
print("Cipher: ", cipher)

frequency_of_zero = calculate_frequency(cipher, "0")
print("Frequency of the zero in the cipher text: ", frequency_of_zero)



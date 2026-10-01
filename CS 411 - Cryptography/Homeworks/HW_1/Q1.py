# Emir Asal 27933 - CS 411 HW01 - Question 1 

#Cipher Text = "NGZZK"
cipher_indexes=[13, 6, 25, 25, 10]

possible_words = []
letters = list(map(chr, range(65, 91))) # Every letters


for k in range(0,27):
    word = ""
    for i in cipher_indexes:
        word += letters[(i-k)]

    possible_words.append(word)

print(possible_words)
print("Meaningful words are: ", possible_words[12], "and", possible_words[21])
print("Their keys are:", 12, "and", 21)
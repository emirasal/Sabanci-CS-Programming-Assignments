# Emir Asal 27933 - CS 411 HW01 - Question 7

from hw01_helper import uppercase, inv_uppercase

# Removing everything except letters
def strip (text):
    new_text = ""
    for letter in text:
        if letter in uppercase:
            new_text += letter
    return new_text

# Moving the text with the given amount so that we can find the key length
def move_text(text, amount):
    new_text = ""
    for i in range(amount, len(text)):
        new_text += text[i]
    return new_text

# Shifting the text to be used in the frequency analysis
def shift(text, shift_amount):
    new_text = ""
    for letter in text:
        new_letter_in_num = (uppercase.get(letter) + shift_amount)%26
        new_letter = inv_uppercase.get(new_letter_in_num)
        new_text += new_letter
    return new_text

# Checking for matching letters in the given text and cipher text.
def check_coincidence(text):
    coincidence = 0
    for i in range(0, len(text)):
        if (cipher_only_letters[i] == text[i]):
            coincidence+=1
    return coincidence

# Counting the every letter in a text then calculating the frequency of that letter. And then adding to the dictionary.
def calculate_frequency (text):
    count_dict = letter_count
    for char in text:
        count_dict[char] += 1
    for value in count_dict:
        count_dict[value] = count_dict[value] / len(text)
    return count_dict

# Comparing two dictionary and returning their difference.
# This is used to find that so we can find which shift is closer to the eng letter frequency.
def compare (dict):
    my_list = list(dict.values())
    deviancy = 0.0
    eng_letter_freqency_list = list(eng_letter_freqency.values())
    for i in range(0, len(eng_letter_freqency_list)):
        if my_list[i] > eng_letter_freqency_list[i]:
            deviancy += (my_list[i] - eng_letter_freqency_list[i])
        else:
            deviancy += (eng_letter_freqency_list[i] - my_list[i])
    return float(deviancy)


####### Finding the Key Lenght
cipher = "JR WYDUGQ AR LRG BTFWB’U UECDC YVTF S CYVNE LY JVS QZYWYDCJC, CAD FAC NRGQ KZTRAB MXYVTRAXIYY, YK SH GHC DOXRL DDYQES UWBG GIJLSPT UN SXF FILCSPT DMOX VB TFW RGNVC SXF YULYO QS TFW CGN. TFW GKQE PGYOF SCWWGQ TMG XCERMO PQE HGK BQYLGFQ INIR, SXF GO FAWURLD ZO YNS GF DGERMJ VGFT FAC DEOYV CJBUJVOTF SFGENQ CMDVKQE UADJ GHC VYQEWYQC QE SUWOR GHC TBKP-A-ZJKE SRME DJR LMO WCATCD. RG EEAGSNRD DJYO FIBW DQ FIBW LGGWCWX VUE TSBKBUQ GLLRCRK KPQ MSDDKCLGWN VUE FSJCEDQ LRCG IL JOCYIRQ VQQGCV YPYY GF RKF MGFN. DRTUWOP N GPSXF CIYFY CAD Y UOPGRC-LKDYE NAVGQ HGYR YVTF TYQXS USC UCAAW PQE A FSVH N DMROP GO USVM NBPWKUG, YCL RG RSQSIGQ IR OSVU TPWZKQARAYP. UIQ ZOCIY YJWU UULY VQBSCDI CG HGK CKQEQ. ZO FVD LGD MAOU ORCG TM VY YVTF LRQFE YJWU NNB ZKPQS, YFN YUEL, LY JVS CPMKGEB NSUVOL, GXG NRK KOGZEB DSCOLC LY DEUQZ KINILKD VUE ZGYMF OL LRG GAZDO, JR LSJMJRD YOKA YIIW K HEIEZDGAEB ZYTFE, ZSBGYY KACUVNE LRG CIYFY UGOMD. RG JARURGQ TFW OCFY USVM BF RZO QGHCJ SP SRMFD QS HGE, KPQ FMJ DJR FGJCV GIKW BGNLGROF GHYL RKF WYDU YNS BAPHRRCFD HEOK LRCG OD GDJRR KWX. JR EVHOTVELUOF N MMEOPGAPQ ZCAG MX CJNMC LRCG HC KRQHLB OKNX SM MXEBURZVA. GHC KGGNT ZMBUG TFJYWTH RZO UXIL GP JVS DGBGUEYV SP GILQ LGNDQ, SXF UE NSEURD YFN OBPNWN JVS ZJYPMEB XKER WGLR JVS FSXFXEPURKRF."
cipher_only_letters = strip(cipher)
print(cipher_only_letters)
for i in range(1,11):
    shifted_text = move_text(cipher_only_letters, i)
    print(i, ": ", check_coincidence(shifted_text))
    
# key length is 6. Because when we move the letters 6 times the coincidences spiked.
key_length = 6
print("Coincidences spiked at 6. Length of the Key:", key_length)


eng_letter_freqency = {'A':0.082, 'B':0.015, 'C':0.028, 'D':0.043, 'E':0.127, 'F':0.022, 'G':0.02, 'H':0.061, 'I':0.07,
         'J':0.002, 'K':0.008, 'L':0.04, 'M':0.024, 'N':0.067, 'O':0.075, 'P':0.019, 'Q':0.001,
         'R':0.06, 'S':0.063,  'T':0.091, 'U':0.028, 'V':0.01, 'W':0.023, 'X':0.001, 'Y':0.02, 'Z':0.001}

letter_count = {'A':0, 'B':0, 'C':0, 'D':0, 'E':0, 'F':0, 'G':0, 'H':0, 'I':0,
         'J':0, 'K':0, 'L':0, 'M':0, 'N':0, 'O':0, 'P':0, 'Q':0,
         'R':0, 'S':0,  'T':0, 'U':0, 'V':0, 'W':0, 'X':0, 'Y':0, 'Z':0}


key = []
for k in range(0,6):

    # We create 6 different subciphers
    sub_cipher = ""
    for i in range(k,len(cipher_only_letters), 6):
        sub_cipher += cipher_only_letters[i]
    
    
    lowest_deviancy = 100 # I Made up big number
    best_shift = 0        # Starting from shift 0
    for s in range (0, 26):
        shifted_sub_cipher = shift(sub_cipher, s)
        frequency_dict = calculate_frequency(shifted_sub_cipher)
        deviancy = compare(frequency_dict)

        if deviancy < lowest_deviancy:
            lowest_deviancy = deviancy
            best_shift = s
    
    key.append(best_shift)

print("The Key is:", key)


# Decryption Starts Here
plain_text = ""
key_pos = 0    # This variable is used to keep track of the amount of shift we need do to the text. (Our position in the key)
for char in cipher:
    if char in uppercase:
        new_char_in_num = (uppercase.get(char) + key[key_pos])%26
        new_char = inv_uppercase.get(new_char_in_num)
        plain_text += new_char
        key_pos += 1
    else:
        plain_text += char

    # Position of the key cannot be bigger 6. Because of the key length max index is 5.
    if key_pos == 6:
        key_pos = 0


print("Decrypted Plain Text: ", plain_text)


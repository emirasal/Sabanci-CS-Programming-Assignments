from lfsr import *
import random


lengths = [128, 128, 64]
Ls = [6, 6, 5]     # Max degrees

# We will try for p1, p2, p3
for i in range(0,3):
    L = Ls[i]
    C = [0]*(L+1)
    S = [0]*L

    if i == 0: # x^6 + x^5 + x^4 + x + 1
        C[0] = C[1] = C[4] = C[5] = C[6] = 1
    elif i == 1: # x^6 + x^2 + 1
        C[0] = C[2] = C[6] = 1
    else: # x^5 + x^3 + 1
        C[0] = C[3] = C[5] = 1


    for k in range(0,L):            # for random initial state
        S[k] = random.randint(0, 1)
    print ("Initial state: ", S) 


    keystream = [0]*lengths[i]
    for m in range(0,lengths[i]):
        keystream[m] = LFSR(C, S)

    period = FindPeriod(keystream)
    max_period = (2**Ls[i])-1
    print ("Period is ", period)
    print ("Max Period is", max_period)

    if (period == max_period):
        print("p",i+1, "generates a maximum period sequence which is", max_period)
    else:
        print("p", i+1, "did not generate a maximum period sequence.")
    print("***************")


print("x6 + x5 + x4 + x + 1 polynomial generated the maximum period sequence")
print("x5 + x3 + 1 polynomial generated the maximum period sequence")
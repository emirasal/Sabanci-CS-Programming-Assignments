from client import *

## Part A
n, t = getQ1()
checkQ1a(n-1)




## Part B
divisors = []
# Finding the divisors of 732 
for i in range(1, 733):
    if(732 % i == 0):
        divisors.append(i)

print("Divisors of 732:", divisors)


Z = range(0,733)
generator = 1
sub_group = []
while generator < 732:
    # We try for every possible sub group generator
    for i in range(0, 733, generator):
        sub_group.append(Z[i])
    if len(sub_group) in divisors:
        print("Correct generator is found!", generator)
        break
    # Not found we try again with the next generator
    generator += 1
    sub_group = []

checkQ1b(generator)



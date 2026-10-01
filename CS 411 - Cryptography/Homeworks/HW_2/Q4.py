import math

# PART a
n = 1593089977489628213419978935847037520292814625191902216371975
a = 1085484459548069946264190994325065981547479490357385174198606
b = 953189746439821656094084356255725844528749341834716784445794

d = math.gcd(a, n)
print("gcd(a, n) for Part a:", d)

# When gcd(a, n) is 1:
x = b * pow(a,-1) % n
print("x Solution for Part a:", x)


print("")





# PART b

n = 1604381279648013370121337611949677864830039917668320704906912
a = 363513302982222769246854729203529628172715297372073676369299
b = 1306899432917281278335140993361301678049317527759257978568241

d = math.gcd(a, n)
print("gcd(a, n) for Part b:", d)

# When gcd != 1:

# Checking if solution exists
s = b / d
if b % d == 0: # There are d solutions
    solutions = []
    for i in range(d):
        x = (pow((a/d),-1) * (b/d)) % (n/d)
        solutions.append(x + ((n/d)*i))
    print(solutions)
else:
    print("No solution exits for part b")


print("")

# PART c

n = 591375382219300240363628802132113226233154663323164696317092
a = 1143601365013264416361441429727110867366620091483828932889862
b = 368444135753187037947211618249879699701466381631559610698826

d = math.gcd(a, n)
print("gcd(a, n) for Part c:", d)

# When gcd != 1:
# Checking if solution exists
if b % d == 0: # There are d number of solutions
    solutions = []
    for i in range(d):
        x = (pow((a/d),-1) * (b/d)) % (n/d)
        solutions.append(x + ((n/d)*i))
    print("Solutions for part c", solutions)
else:
    print("No solution exits for part c")


print("")



# PART d

n = 72223241701063812950018534557861370515090379790101401906496
a = 798442746309714903219853299207137826650460450190001016593820
b = 263077027284763417836483401088884721142505761791336585685868

d = math.gcd(a, n)
print("gcd(a, n) for Part d:", d)

# When gcd != 1:
# Checking if solution exists
if b % d == 0: # There are d number of solutions
    solutions = []
    for i in range(d):
        x = (pow((a/d),-1) * (b/d)) % (n/d)
        solutions.append(x + (n/d)*i)
    print("Solutions for part d: ", solutions)
else:
    print("No solution exits for part d")
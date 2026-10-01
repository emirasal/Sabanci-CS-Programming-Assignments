from math import gcd
##SOLUTION OF Q1 
#n, t = getQ1()
n, t = 722, 9
group = set(a for a in range(1, n) if gcd(a,n)==1)  #this is Z*_n
g = 0
gH = 0
for a in group:
  gens = set()
  for x in range(1,n):
    gens.add(pow(a,x,n))
  if gens == group:
    g = a   #found the generator
    break

for a in group:
  chk = 0
  for i in range(1,t):
    if pow(a, i, n) == 1:
      chk = 1
      break
  if chk == 0 and pow(a, t, n) == 1:
    gH = a    #found the gnerator of the subgroup H (order(H) = t)
    break
print("part a: ", len(group))   
print("part b: ", g)   
print("part c: ", gH)   

# checkQ1a(len(group))
# checkQ1b(g)
# checkQ1c(gH)
##END OF SOLUTION OF Q1

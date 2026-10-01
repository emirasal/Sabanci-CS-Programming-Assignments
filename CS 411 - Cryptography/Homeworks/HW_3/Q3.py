def XOR(a, b):
    if a==b: return 0
    else: return 1

def function(x1, x2 , x3, x4):
    result = XOR(x1, x1*x2) 
    result = XOR(result, x2*x3)
    result = XOR(result, x2*x3*x4)
    result = XOR(result, x1*x2*x3*x4)
    return result

# 2^16 different binary sequences
# First we calculate the balance
zeroCount = 0
oneCount = 0
zList = []

for i in range(0, 16):
    xValues = '{0:04b}'.format(i)
    x1=int(xValues[0])
    x2=int(xValues[1])
    x3=int(xValues[2])
    x4=int(xValues[3])

    z = function(x1, x2, x3, x4)

    zList.append(z)

    if z == 0: zeroCount += 1
    else: oneCount += 1

print("Count of 0 in z: ", zeroCount)
print("Count of 1 in z: ", oneCount)
print("They are very close so it is balanced")
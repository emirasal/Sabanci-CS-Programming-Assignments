import random
import requests
import BitVector

API_URL = 'http://10.92.55.4:6000'
my_id = 26045
def get_poly():
  endpoint = '{}/{}/{}'.format(API_URL, "poly", my_id )
  response = requests.get(endpoint) 	
  a = 0
  b = 0
  if response.ok:	
    res = response.json()
    print(res)
    return res['a'], res['b']
  else:
    print(response.json())

def check_mult(c):
  #check result of part a
  endpoint = '{}/{}/{}/{}'.format(API_URL, "mult", my_id, c)
  response = requests.put(endpoint) 	
  print(response.json())

def check_inv(a_inv):
  #check result of part b
  response = requests.put('{}/{}/{}/{}'.format(API_URL, "inv", my_id, a_inv)) 
  print(response.json())

a, b = get_poly()
##SOLUTION  
px = '100011011'  
px_ = BitVector.BitVector(bitstring = px)
n = 8

a_ = BitVector.BitVector(bitstring = a)
b_ = BitVector.BitVector(bitstring = b)

c = a_.gf_multiply_modular(b_, px_, n)
a_inv = a_.gf_MI(px_, n)
##END OF SOLUTION

check_mult(c)
check_inv(a_inv)

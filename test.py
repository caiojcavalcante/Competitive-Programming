from math import sqrt

def isprime(n):
    for i in range(2, int(sqrt(n))+1):
        if(not(n % i)): return 0
    return 1
    
    
from time import time

init = time()

cont = 1
for i in range(3,10000000000000):
        if(isprime(i)): cont+=1
        # print(time()-init)
        if(time()-init >= 60): break
        
print(cont)
        
        
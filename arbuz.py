import numpy as np
def f(nabor):
    res = []
    for n,k,s in nabor:
        Price = np.zeros(k,dtype = int)
        for i in range (k):
            b,c = s[i]
            Price[b-1]+=c
        summ = np.partition(Price,-n)[-n:]
        res.append(summ.sum())
    return res          
                       


t = int(input())
nabor = []
for i in range(t):
    n,k = map(int,input().split())
    s = [tuple(map(int,input().split())) for j in range(k)]
    nabor.append((n,k,s))

for i in f(nabor):
    print(i)

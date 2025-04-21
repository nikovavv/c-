# n = int(input())
# p = 0
# for i in range(1,n-1):
#     for j in range(i+1,n):
#         for k in range(j+1,n+1):
#             if i<j+k and j<i+k and k<j+i:
#                 if max(i,j,k)**2==(min(i,j,k)**2+(i+j+k-max(i,j,k)-min(i,j,k))**2):
#                     p+=1
# print(p)            


# from itertools import product

# def f(target):
#     d = "123456789"
#     n = len(d) - 1
#     for signs in product(["", "+", "-"], repeat=n):
#         e = d[0]
#         for digit, sign in zip(d[1:], signs):
#             e += sign + digit
#         if eval(e) == target:
#             return e
#     return "Нет решения"
# m = int(input())
# result = f(m)
# print(result)

# def sumdel(n):
#     su = 1
#     for i in range(2,int(n**0.5)+1):
#         if n%i==0:
#             su+=i
#             if i != n//i:
#                 su+=n//i
#     return su

# def f(s,k):
#     for i in range(s,k+1):
#         j = sumdel(i)
#         if  j<=k and sumdel(j)==i:
#             print(i,j)    
# print(f(10,2000))                    


# def f(x,y):
#     if x==y:return 1
#     if x>y:return 0
#     if x%2==0:return f(x+1,y)+f(x+2,y)
#     else:return f(x+x%4,y)
# n = int(input())    
# print(f(0,n))    
    
    
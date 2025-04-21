#1
# def puzir(a):
#     n = len(a)
#     for i in range(n-1):
#         for j in range(n-1-i):
#             if a[j+1]<a[j]:
#                 a[j+1],a[j]=a[j],a[j+1]
#     return a       
    
# a = [99,36,1,45,278,999,32]
# print(a) 
# print(puzir(a))   



#2
# def shaker(a):
#     n = len(a)
#     l = 0
#     r = n-1
#     while l<r:
#         for i in range(l,r):
#             if a[i]>a[i+1]:
#                 a[i],a[i+1]=a[i+1],a[i]
#         r-=1
#         for i in range(r,l,-1):
#             if a[i]<a[i-1]:
#                 a[i],a[i-1]=a[i-1],a[i]
#         l+=1
#     return a    
# a = [99,36,1,45,278,999,32]
# print(a)
# print(shaker(a))                        


#3
# def vstavka(a):
#     for i in range(1,len(a)):
#         k = a[i]
#         j = i-1
#         while j>=0 and a[j]>k:
#             a[j+1] = a[j]
#             j -= 1 
#         a[j+1] = k
#     return a

# a = [99,36,1,45,278,999,32]
# print(a)
# print(vstavka(a))                 

#4
# def vyborka(a):
#     for i in range(len(a)):
#         minn=i
#         for j in range(i+1,len(a)):
#             if a[j]<a[minn]:
#                 minn = j 
#         a[i],a[minn]=a[minn],a[i]   
#     return a

# a = [99,36,1,45,278,999,32]
# print(a)
# print(vyborka(a))                 


#5
# def shell(a):
#     n = len(a)
#     g = n//2
#     while g > 0:
#         for i in range(g,n):
#             t = a[i]
#             j = i
#             while j>=g and a[j-g]>t:
#                 a[j] = a[j-g]
#                 j -= g        
#             a[j] = t
#         g//=2
#     return a
        
# a = [99,36,1,45,278,999,32]
# print(a)
# print(shell(a))            


#6
# def qsort(a):
#     if len(a)<=1:return a
#     nach = a[-1]
#     l = [i for i in a[:-1] if i<=nach] 
#     r = [i for i in a[:-1] if i>nach]
#     return qsort(l)+[nach]+qsort(r)     

# a = [99,36,1,45,278,999,32]
# print(a)
# print(qsort(a))  

#7
# import random
# import time
# def puzir(a):
#     n = len(a)
#     for i in range(n-1):
#         for j in range(n-1-i):
#             if a[j+1]<a[j]:
#                 a[j+1],a[j]=a[j],a[j+1]
#     return a   

# def shaker(a):
#     n = len(a)
#     l = 0
#     r = n-1
#     while l<r:
#         for i in range(l,r):
#             if a[i]>a[i+1]:
#                 a[i],a[i+1]=a[i+1],a[i]
#         r-=1
#         for i in range(r,l,-1):
#             if a[i]<a[i-1]:
#                 a[i],a[i-1]=a[i-1],a[i]
#         l+=1
#     return a    

# def vstavka(a):
#     for i in range(1,len(a)):
#         k = a[i]
#         j = i-1
#         while j>=0 and a[j]>k:
#             a[j+1] = a[j]
#             j -= 1 
#         a[j+1] = k
#     return a

# def vyborka(a):
#     for i in range(len(a)):
#         minn=i
#         for j in range(i+1,len(a)):
#             if a[j]<a[minn]:
#                 minn = j 
#         a[i],a[minn]=a[minn],a[i]   
#     return a

# def shell(a):
#     n = len(a)
#     g = n//2
#     while g > 0:
#         for i in range(g,n):
#             t = a[i]
#             j = i
#             while j>=g and a[j-g]>t:
#                 a[j] = a[j-g]
#                 j -= g        
#             a[j] = t
#         g//=2
#     return a

# def qsort(a):
#     if len(a)<=1:return a
#     nach = a[-1]
#     l = [i for i in a[:-1] if i<=nach] 
#     r = [i for i in a[:-1] if i>nach]
#     return qsort(l)+[nach]+qsort(r)   
                    
# array = [random.randint(1, 999) for _ in range(5000)]

# algorithms = {
#     "Bubble Sort": puzir,
#     "Shaker Sort": shaker,
#     "Insertion Sort": vstavka,
#     "Selection Sort": vyborka,
#     "Shell Sort": shell,
#     "Quick Sort": qsort
# }

# for name, func in algorithms.items():
#     start_time = time.time()
#     func(array.copy())
#     end_time = time.time()

#     print(name, end_time - start_time)


#8
# import random
# import time
# def binary(a,s,l,r):
#     while l<=r:
#         mid = (l+r)//2
#         if a[mid]==s:
#             return mid
#         elif a[mid]<s:
#             l = mid+1
#         else:
#             r = mid-1
#     return l            

# def sort(a):
#     for i in range(1,len(a)):
#         s = a[i]
#         l = 0
#         r = i-1
#         pos = binary(a,s,l,r)
#         for j in range(i,pos,-1):
#             a[j] = a[j-1]
#         a[pos] = s   
#     return a    
# def vstavka(a):
#     for i in range(1,len(a)):
#         k = a[i]
#         j = i-1
#         while j>=0 and a[j]>k:
#             a[j+1] = a[j]
#             j -= 1 
#         a[j+1] = k
#     return a        
# array = [random.randint(1, 999) for _ in range(5000)]

# algorithms = {
#     "Binary": sort,
#     "Insertion Sort": vstavka,
# }

# for name, func in algorithms.items():
#     start_time = time.time()
#     func(array.copy())
#     end_time = time.time()
#     print(name, end_time - start_time)


# def delitel(x,y):
#     print(x // y)
#     print(x % y)

# x = int(input())
# y = int(input())
# delitel(x,y)

# def pal(x):
#     a = x[::-1]
#     if x == a:
#         print("yes")
#     else:
#         print("no")

# x = str(input())
# pal(x)

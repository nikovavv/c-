#1
def f(a,b):
    a = abs(a)
    b = abs(b)
    if a==0 or b==0:
        a+=b
        b+=a
    if a==b:return a
    elif a>b:return f(a-b,b)
    else:return f(b-a,a)
a = int(input())
b = int(input())
print("НОД этих чисел равен",f(a,b))    

#2
# def fibonacchi(n):
#     if n in(1,2):return 1
#     else:return fibonacchi(n-1)+fibonacchi(n-2)

# a = int(input())    
# print(fibonacchi(a))    

#3

# def func(n):return n**5-n-0.2
# def f(l,r,e = 0.0001):
#     b = (l+r)/2
#     if (abs(l-r)<=e): return b
#     else: 
#         b = (l+r)/2
#         if (func(l)*func(b)>0):
#             return f(b,r,e)
#         else: return f(l,b,e)   

# b= f(1,2)
# print(b,func(b))
            
#4
# def chisla(n):
#     if n<10:return n
#     else:return n%10+chisla(n//10)

# n = int(input())
# print(chisla(n))                

#5
# def deikstra(n):
#     if n==1:return 1
#     if (n%2)==0: return deikstra(n/2)
#     else: return deikstra((n-1)/2)+deikstra((n-1)/2+1)
    
# n = int(input())
# print(deikstra(n))    

#6
# def perenos(n,a,b,c):
#     if n==1:
#         print(f"Block 1 move from {a} to {b}")
#         return
#     else:
#         perenos(n - 1, a, c, b); 
#         print(f"Block {n} move from {a} to {b}")
#         perenos(n - 1, c,b,a); 


# n = int(input())
# perenos(n, 1, 3, 2)

#7
# def hash(key,size):return key%size
# def tohash(tabl,key):
#     size = len(tabl)
#     index = hash(key,size)
#     ind = index
#     while tabl[index] is not None:
#         index = (index+1)%size
#         if index==ind:
#             print("Ошибка")
#             return
#     tabl[index] = key    
# size = 7
# hash1 = [None]*size
# n = [86,90,27,29,38,30,40]
# for i in n:
#     tohash(hash1,i)
# print(hash1)    

#7.1
# def hash_function(key):
#     return key % size
# data = [86, 90, 27, 29, 38, 30, 40]
# size = 7
# hash_table = {i: [] for i in range(size)}
# for i in data:
#     index = hash_function(i)
#     hash_table[index].append(i)
# print(hash_table)

#8
# class HashTable:
#     def __init__(self, size=100):
#         self.size = size
#         self.table = [[] for _ in range(size)]
#     def hash_function(self, key):
#         if isinstance(key, int):
#             return key % self.size
#         elif isinstance(key, str):
#             return sum(ord(char) for char in key) % self.size
#     def add(self, key, value):
#         index = self.hash_function(key)
#         for pair in self.table[index]:
#             if pair[0] == key:
#                 pair[1].append(value)
#                 return
#         self.table[index].append([key, [value]])
#     def get(self, key):
#         index = self.hash_function(key)
#         for pair in self.table[index]:
#             if pair[0] == key:
#                 return pair[1]
#         return None
#     def remove(self, key, value):
#         index = self.hash_function(key)
#         for pair in self.table[index]:
#             if pair[0] == key:
#                 if value in pair[1]:
#                     pair[1].remove(value)
#                     if not pair[1]:
#                         self.table[index].remove(pair)
#                 return
#     def display(self):
#         for index, bucket in enumerate(self.table):
#             if bucket:
#                 print(f"{bucket}")
                
# phone_book = HashTable()
# phone_book.add("Антонов", "123-456-7890")
# phone_book.add("Антонов", "987-654-3210")
# phone_book.add("Черничкин", "666-666-6666")
# phone_book.add("Сидоров", "222-222-2222")
# print("Номера Антонова:", phone_book.get("Антонов"))
# print("Номер Черничкина:", phone_book.get("Черничкин"))
# phone_book.remove("Антонов", "123-456-7890")
# print("Номера Антонова после удаления:", phone_book.get("Антонов"))
# phone_book.display()


#9
# def hashtabl(str):
#     A = {}
#     for i in str:
#         if i in A:
#             A[i]+=1
#         else:
#             A[i]=1 
#     return A 

# s = str(input())
# print(hashtabl(s))          


#10
# def two_sum(nums, n):
#     hash_table = {}
#     for index, num in enumerate(nums):
#         c = n - num
#         if c in hash_table:
#             return [hash_table[c], index]
#         hash_table[num] = index
#     return None
# nums = [int(i) for i in input().split()]
# n = int(input())
# result = two_sum(nums, n)

# if result:
#     print("Индексы:", result)
# else:
#     print("Пара не найдена")

#11
# import json
# from collections import defaultdict
# def json_to_hash_table():
#     json_data = json.loads(open("data.json").read())
#     hash_table = defaultdict(list)

#     for item in json_data:
#         hash_table[item["id"]].append(item["name"])

#     return dict(hash_table)
# print("Хэш-таблица:", json_to_hash_table())
#1
# def sravnenie(n1,n2):
#     if len(n1)>len(n2):return 1
#     elif len(n1)<len(n2):return -1
#     else:
#         for i in range(len(n1)):
#             if int(n1[i])>int(n2[i]):
#                 return 1
#             elif int(n1[i])<int(n2[i]):
#                 return -1
#         return 0
    
# def adds(n1,n2):
#     n1 = n1[::-1]
#     n2 = n2[::-1]
#     maxlen = max(len(n1),len(n2))
#     res = []
#     k = 0
#     for i in range(maxlen):
#         total = (int(n1[i]) if i<len(n1) else 0)+(int(n2[i]) if i<len(n2) else 0)+int(k)
#         res.append(total%10)
#         k = total//10
#     if k==1:res.append(k)
#     return "".join(map(str,res[::-1]))
# def razn(n1,n2):
#     if sravnenie(n1,n2)<0:n1,n2=n2,n1
#     n1,n2=n1[::-1],n2[::-1]
#     res = []
#     k = 0
#     for i in range(len(n1)):
#         total = (int(n1[i]) if i<len(n1) else 0)-(int(n2[i]) if i<len(n2) else 0)-int(k)
#         res.append(total%10 if total>=0 else total+10)
#         k = 1 if total<0 else 0
#     while res[-1]==0 and len(res)>1: res.pop()    
#     return "".join(map(str,res[::-1]))
    
# a = input("Введите 1 число: ")
# b = input("Введите знак ")
# c = input("Введите 2 число: ")

# if b=="+":
#     print("Результат суммы: ", adds(a,c))
# else:
#     print("Результат разности: ", razn(a,c))    
  
  
  
#2
# def addition(a, b):
#     a = list(map(int, a))
#     b = list(map(int, b))
#     n = len(a)
#     sum_result = [0] * n  
#     carry = [0] * (n + 1)
#     for i in range(n-1, -1, -1):
#         sum_result[i] = a[i] ^ b[i] ^ carry[i + 1]  
#         carry[i] = (a[i] & b[i]) | (a[i] & carry[i + 1]) | (b[i] & carry[i + 1]) 
#     final_result = [carry[0]] + sum_result if carry[0] else sum_result
#     return ''.join(map(str, final_result))


# a = input("Введите первое двоичное число: ")
# b = input("Введите второе двоичное число: ")
# max_len = max(len(a), len(b))
# a = a.zfill(max_len)
# b = b.zfill(max_len)

# result = addition(a, b)

# print("Результат ускоренного сложения:", result)  

#3
# Функция ускоренного сложения двух десятичных чисел
# def addition(a, b):
#     a = list(map(int, a)) 
#     n = len(a)
#     carry = 0  
#     result = [] 
#     for i in range(n - 1, -1, -1):
#         total = int(a[i]) + int(b[i]) + carry
#         result.append(total % 10)   
#         carry = total // 10        
#     if carry==1:result.append(carry)
#     return ''.join(map(str, result[::-1]))

# a = input("Введите первое десятичное число: ")
# b = input("Введите второе десятичное число: ")

# max_len = max(len(a), len(b))
# a = a.zfill(max_len)
# b = b.zfill(max_len)
# print("Результат сложения:",addition(a, b))

#4
# def multiply(num1, num2):
#     result = [0] * (len(num1) + len(num2))
#     for i in range(len(num1)-1, -1, -1):
#         for j in range(len(num2)-1, -1, -1):
#             mul = int(num1[i]) * int(num2[j])
#             p1, p2 = i + j, i + j + 1
#             summation = mul + result[p2]
#             result[p2] = summation % 10
#             result[p1] += summation // 10
#     result_str = ''.join(map(str, result))
#     return result_str.lstrip('0') or '0'


# num1 = input("Введите первое число: ")
# num2 = input("Введите второе число: ")

# product = multiply(num1, num2)

# print(f"Произведение: {product}")


#5
# def karatsuba(x, y):
#     if x < 10 or y < 10:
#         return x * y
#     n = max(len(str(x)), len(str(y)))
#     m = n // 2
#     high1, low1 = divmod(x, 10**m)
#     high2, low2 = divmod(y, 10**m)
#     z0 = karatsuba(low1, low2)
#     z1 = karatsuba((low1 + high1), (low2 + high2))
#     z2 = karatsuba(high1, high2)
#     return (z2 * 10**(2*m)) + ((z1 - z2 - z0) * 10**m) + z0

# x = int(input())
# y = int(input())
# result = karatsuba(x, y)
# print(f"Результат умножения: {result}")


#6
# def binary_division(dividend, divisor):
#     if divisor == 0:
#         raise ValueError("Деление на ноль невозможно!")
#     negative = (dividend < 0) != (divisor < 0)
#     dividend = abs(dividend)
#     divisor = abs(divisor)
#     left, right = 0, dividend
#     while left <= right:
#         mid = (left + right) // 2
#         if mid * divisor <= dividend:
#             quotient = mid
#             left = mid + 1
#         else:
#             right = mid - 1
#     remainder = dividend - quotient * divisor
#     if negative:
#         quotient = -quotient
#     return quotient, remainder


# dividend = int(input())
# divisor = int(input())

# quotient, remainder = binary_division(dividend, divisor)
# print(f"Частное: {quotient}, Остаток: {remainder}")
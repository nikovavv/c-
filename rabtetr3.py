# 1
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
    
# def summ(n1,n2):
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
#     print("Результат суммы: ", summ(a,c))
# else:
#     print("Результат разности: ", razn(a,c))    
  
  
  
#2
# a = input("Введите первое двоичное число: ")
# b = input("Введите второе двоичное число: ")
# max_len = max(len(a), len(b))
# a = a.zfill(max_len)
# b = b.zfill(max_len)
# a1 = [int(i) for i in a]
# b1 = [int(i) for i in b]
# print([0] + a1[::-1])
# print([0] + b1[::-1])
# print()
# a = [int(elem) for elem in a[::-1]]
# b = [int(elem) for elem in b[::-1]]
# n = len(a)
# sum_result = [0] * (n+1)  
# perenos = [0] * (n + 1)
# while True:
#     for i in range(len(a) + 1):
#         if i != len(a) and a[i] + b[i] not in [0, 2]:
#             sum_result[i] = 1
#         if i != 0 and a[i - 1] + b[i - 1] == 2:
#             perenos[i] = 1
#     if 1 in perenos:
#         print(sum_result[::-1])
#         print(perenos[::-1])
#         print()
#         a = sum_result
#         b = perenos
#         sum_result = [0] * len(a)
#         perenos = [0] * len(a)
#     else:
#         break
# print(sum_result[::-1])
# print(perenos[::-1])

#3
# a = input("Введите первое десятичное число: ")
# b = input("Введите второе десятичное число: ")
# max_len = max(len(a), len(b))
# a = a.zfill(max_len)
# b = b.zfill(max_len)
# a1 = [int(i) for i in a]
# b1 = [int(i) for i in b]
# print([0] + a1[::-1])
# print([0] + b1[::-1])
# print()
# a = [int(elem) for elem in a[::-1]]
# b = [int(elem) for elem in b[::-1]]
# n = len(a)
# sum_result = [0] * (n+1)  
# perenos = [0] * (n + 1)
# while True:
#     for i in range(len(a) + 1):
#         if i != len(a):
#             sum_result[i] = (a[i]+b[i])%10
#         if i != 0 and a[i - 1] + b[i - 1] >9:
#             perenos[i] = 1
#     if 1 in perenos:
#         print(sum_result[::-1])
#         print(perenos[::-1])
#         print()
#         a = sum_result
#         b = perenos
#         sum_result = [0] * len(a)
#         perenos = [0] * len(a)
#     else:
#         break
# print(sum_result[::-1])
# print(perenos[::-1])

#3
# def addition(a, b):
#     a = list(map(int, a))
#     b = list(map(int, b))
#     n = len(a)
#     sum_result = [0] * n  
#     perenos = 0
#     for i in range(n-1, -1, -1):
#         vrem_sum = a[i] + b[i] + perenos
#         sum_result[i]=vrem_sum%10
#         perenos =  vrem_sum//10
#     final_result = [perenos] + sum_result if perenos else sum_result
#     return ''.join(map(str, final_result))

# a = input("Введите первое десятичное число: ")
# b = input("Введите второе десятичное число: ")
# max_len = max(len(a), len(b))
# a = a.zfill(max_len)
# b = b.zfill(max_len)
# result = addition(a, b)
# print("Результат ускоренного сложения:", result)  

# #4
# def multiply(n1, n2):
#     result = [0] * (len(n1) + len(n2))
#     for i in range(len(n1)-1, -1, -1):
#         for j in range(len(n2)-1, -1, -1):
#             mul = int(n1[i]) * int(n2[j])
#             p1, p2 = i + j, i + j + 1
#             summ = mul + result[p2]
#             result[p2] = summ % 10
#             result[p1] += summ // 10
#     result_str = ''.join(map(str, result))
#     return result_str.lstrip('0') or '0'

# n1 = input("Введите первое число: ")
# n2 = input("Введите второе число: ")
# product = multiply(n1, n2)
# print(f"Произведение: {product}")





#5
# import random
# import time
# def multiply(n1, n2):
#     result = [0] * (len(n1) + len(n2))
#     for i in range(len(n1)-1, -1, -1):
#         for j in range(len(n2)-1, -1, -1):
#             mul = int(n1[i]) * int(n2[j])
#             p1, p2 = i + j, i + j + 1
#             summ = mul + result[p2]
#             result[p2] = summ % 10
#             result[p1] += summ // 10
#     result_str = ''.join(map(str, result))
#     return result_str.lstrip('0') or '0'
# def karatsuba(x, y):
#     x = int(x)
#     y = int(y)
#     if x < 10 or y < 10:
#         return x * y
#     n = max(len(str(x)), len(str(y)))
#     m = n // 2
#     h1, l1 = divmod(x, 10**m)
#     h2, l2 = divmod(y, 10**m)
#     z0 = karatsuba(l1, l2)
#     z1 = karatsuba((l1 + h1), (l2 + h2))
#     z2 = karatsuba(h1, h2)
#     return (z2 * 10**(2*m)) + ((z1 - z2 - z0) * 10**m) + z0

# n1 = input()
# n2 = input()
# start_time = time.time()
# result1 = "".join(map(str, (multiply(n1, n2))))
# end_time = time.time()
# time_simple_mul = end_time - start_time
# print("Результат умного умножения:", result1)
# print("Время выполнения умного умножения:", time_simple_mul, "секунд")
# start_time = time.time()
# result2 = karatsuba(n1, n2)
# end_time = time.time()
# time_karatsuba = end_time - start_time
# print("Результат карацубы:", result2)
# print("Время выполнения карацубы:", time_karatsuba, "секунд")

# speedup = time_simple_mul / time_karatsuba
# print("Karatsuba быстрее умного умножения в", speedup, "раз")

#6
# def f(div1, chastnoe):
#     if chastnoe == 0:
#         raise ValueError("error")
#     n = (div1 < 0) != (chastnoe < 0)
#     div1 = abs(div1)
#     chastnoe = abs(chastnoe)
#     left, right = 0, div1
#     while left <= right:
#         mid = (left + right) // 2
#         if mid * chastnoe <= div1:
#             sr = mid
#             left = mid + 1
#         else:
#             right = mid - 1
#     res = div1 - sr * chastnoe
#     if n:
#         sr = -sr
#     return sr, res

# div1 = int(input())
# chastnoe = int(input())
# a, b = f(div1, chastnoe)
# print(f"Частное: {a}, Остаток: {b}")


#6
def normalization(n1, n2):
    if len(n1) < len(n2):
        n1 = [0] * (len(n2) - len(n1)) + n1
    else:
        n2 = [0] * (len(n1) - len(n2)) + n2
    return n1, n2


def zero_deleting(n: list):
    while len(n) > 1 and n[0] == 0:
        n.pop(0)
    return n


def add(n1: list, n2: list):
    n1, n2 = normalization(n1, n2)
    shift = 0
    res = []
    for i in range(len(n1) - 1, -1, -1):
        res.append((n1[i] + n2[i] + shift) % 10)
        shift = (n1[i] + n2[i] + shift) // 10
    if shift:
        res.append(shift)
    return res[::-1]


def sub(n1: list, n2: list):
    n1, n2 = normalization(n1, n2)
    n1, n2 = n1[::-1], n2[::-1]
    borrow = 0
    res_sub = []
    for i in range(len(n1)):
        diff = n1[i] - n2[i] - borrow
        if diff < 0:
            diff += 10
            borrow = 1
        else:
            borrow = 0
        res_sub.append(diff)
    return zero_deleting(res_sub[::-1])


def div_2(n):
    result = []
    carry = 0
    for digit in n:
        current = carry * 10 + digit
        result.append(current // 2)
        carry = current % 2

    while len(result) > 1 and result[0] == 0:
        result.pop(0)

    return result


def le(n1, n2):
    if len(n1) != len(n2):
        return len(n1) < len(n2)

    for d1, d2 in zip(n1, n2):
        if d1 != d2:
            return d1 < d2
    return True


def lt(n1, n2):
    if len(n1) != len(n2):
        return len(n1) < len(n2)

    for d1, d2 in zip(n1, n2):
        if d1 != d2:
            return d1 < d2
    return False


def mul(n1, n2):
    n1, n2 = normalization(n1, n2)
    n1, n2 = n1[::-1], n2[::-1]
    res = [0] * (len(n1) + len(n2))
    shift = 0

    for j in range(len(n2)):
        buffer = [0] * (len(n1) + len(n2))
        for i in range(len(n1)):
            buffer[i] = (n1[i] * n2[j] + shift) % 10
            shift = (n1[i] * n2[j] + shift) // 10
        if shift:
            buffer[i + 1] += shift
            shift = 0
        res = add(buffer[::-1] + [0] * j, res)
    return zero_deleting(res)

def divide_half(a, b):
    if b == [0]:
        raise ValueError("Деление на ноль!")
    if lt(a, b):
        return [0], a

    low, high = [0], a
    while le(low, high):
        mid = div_2(add(low, high))
        product = mul(mid, b)

        if product == a:
            return mid, [0]
        elif lt(product, a):
            low = add(mid, [1])
        else:
            high = sub(mid, [1])

    return high, sub(a, mul(high, b))


n1 = [int(elem) for elem in input("Первое число: ")]
n2 = [int(elem) for elem in input("Второе число: ")]

quotient, remainder = divide_half(n1, n2)
quotient, remainder = "".join(map(str, quotient)), "".join(map(str, remainder))
print(f"Частное: {quotient}, Остаток: {remainder}")
# k = 0
# s = s.replace("{","(")
# s = s.replace("[]","(")
# s = '()[]}'
# for i in s:
#     if i=='(' or i=='{' or i=='[':
#         k+=1 
# if k%2!=0:
#     print('no')
# else:
#     print('yes')    


# def f(s):
#     while "()" in s or  "[]" in s or"{}" in s:
#         s = s.replace("()","")
#         s = s.replace("{}","")
#         s = s.replace("[]","")     
#     if s=="":
#         return "yes"     
#     else:
#         return "no" 
# print(f("(){}["))    



# a = str(input())
# for i in range(len(a)-1):
#     if a[i]==a[i+1]:
#         print('YES')
#         break
# else:
#     print('NO')    

n = int(input())
b = []
for i in range(n):
    s = input().split()
    b.append([int(s[0]),int(s[1])])
b = sorted(b,key=lambda x: x[1],reverse=True)
for i in range(n):
    print(*b[i])
U = set(input().split())
A = set(input().split())
B = set(input().split())
C = set(input().split())

temp =  (U - A) -B
temp_c = U - temp
result = temp_c & C

print(sorted(result))
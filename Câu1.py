
A = set(input().split())
B = set(input().split())
C = set(input().split())


result = (A | B) & C

print(*sorted(result))

import math

n, k = map(int, input().split())

print("C(n, k) =", math.comb(n, k))
print("A(n, k) =", math.perm(n, k))

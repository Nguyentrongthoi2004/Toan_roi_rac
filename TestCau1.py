def comb (n,k):
    if k > n- k :
        k = n -k
    result = 1
    for i in range(k):
        result = result * (n - i) // (i + 1)
    return result

def perm (n,k):
    result =1
    for i in range (k):
        result *= (n - i)
    return result

n = int(input("n:"))
k = int(input("k:"))

print("C ",comb(n,k))
print("P ",perm(n,k))
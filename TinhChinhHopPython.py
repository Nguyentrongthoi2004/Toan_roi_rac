def permutation(n, k):
    result = 1
    for i in range(n, n - k, -1):
        result *= i
    return result

n, k = map(int, input().split())

print(permutation(n, k))

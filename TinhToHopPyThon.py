def combination(n, k):
    if k > n:
        return 0
    if k > n - k:
        k = n - k

    result = 1
    for i in range(1, k + 1):
        result = result * (n - i + 1) // i
    return result


n, k = map(int, input().split())

print(combination(n, k))

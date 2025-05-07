def findunion(A, B):
    union = sorted(set(A) | set(B))
    return union

n, *A = map(int, input().split())
m, *B = map(int, input().split())

print(" ".join(map(str, findunion(A, B))))
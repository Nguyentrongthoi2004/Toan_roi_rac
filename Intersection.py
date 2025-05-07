def find_intersection(A, B):
    intersection = sorted(set(A) & set(B))
    return intersection if intersection else ["none"]

n, *A = map(int, input().split())
m, *B = map(int, input().split())

print(" ".join(map(str, find_intersection(A, B))))
a = list(map(int, input().split()))[1:]
b = list(map(int, input().split()))[1:]

intersection = sorted(set(a) & set(b))
if intersection:
    print(" ".join(map(str, intersection)))
else:
    print("none")

union = sorted(set(a) | set(b))
print(" ".join(map(str, union)))
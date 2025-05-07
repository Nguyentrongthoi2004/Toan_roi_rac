def dfs(start, adj):
    visited, stack, result = set(), [start], []

    while stack:
        u = stack.pop()
        if u not in visited:
            visited.add(u)
            result.append(u)
            stack.extend(reversed(adj[u]))
    return result

if __name__ == "__main__":
    n = int(input())
    adj = [[] for _ in range(n)]

    for i in range(n):
        row = list(map(int, input().split()))
        for j, val in enumerate(row):
            if val == 1:
                adj[i].append(j)

    start = int(input())

    print("Ket qua duyet DFS:")
    print(*dfs(start, adj))

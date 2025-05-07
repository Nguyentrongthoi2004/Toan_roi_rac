from collections import deque

def bfs(start, adj):
    visited, queue, result = set([start]), deque([start]), []

    while queue:
        u = queue.popleft()
        result.append(u)
        for v in adj[u]:
            if v not in visited:
                visited.add(v)
                queue.append(v)
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

    print("Ket qua duyet BFS:")
    print(*bfs(start, adj))

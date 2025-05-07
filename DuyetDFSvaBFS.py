import collections

def dfs(start_node, adj_matrix):
    n = len(adj_matrix)
    visited = [False] * n
    stack = []
    result = []

    stack.append(start_node)

    while stack:
        u = stack.pop()

        if not visited[u]:
            visited[u] = True
            result.append(u)

            for v in range(n - 1, -1, -1):
                if adj_matrix[u][v] == 1 and not visited[v]:
                    stack.append(v)

    return result

def bfs(start_node, adj_matrix):
    n = len(adj_matrix)
    visited = [False] * n
    queue = collections.deque()
    result = []

    visited[start_node] = True
    queue.append(start_node)

    while queue:
        u = queue.popleft()
        result.append(u)

        for v in range(n):
            if adj_matrix[u][v] == 1 and not visited[v]:
                visited[v] = True
                queue.append(v)

    return result

if __name__ == "__main__":
    n = int(input())

    adj_matrix = []
    for _ in range(n):
        row = list(map(int, input().split()))
        adj_matrix.append(row)

    start_node = int(input())

    dfs_result = dfs(start_node, adj_matrix)
    print("Ket qua duyet DFS:")
    print(*dfs_result)

    bfs_result = bfs(start_node, adj_matrix)
    print("Ket qua duyet BFS:")
    print(*bfs_result)
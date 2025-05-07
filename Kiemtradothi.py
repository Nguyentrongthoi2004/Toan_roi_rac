def check_graph_direction(n, matrix):
    for i in range(n):
        for j in range(n):
            if matrix[i][j] != matrix[j][i]:
                return "co_huong"
    return "vo_huong"


n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]

# Kiểm tra và in kết quả
print(check_graph_direction(n, matrix))

#include <stdio.h>
#include <math.h>

int n;                      // Kích thước bàn cờ (n x n)
int column[14];             // Mảng lưu vị trí cột của quân hậu trong từng hàng
int result = 0;             // Biến đếm số cách đặt hợp lệ

int isSafe(int row, int col) {
	for (int i = 0; i < row; i++) {
		if (column[i] == col || abs(column[i] - col) == abs(i - row)) {
			return 0; 
		}
	}
	return 1; 
}

void solve(int row) {
	if (row == n) {
		result++;
		return;
	}
	for (int col = 0; col < n; col++) {
		if (isSafe(row, col)) {
			column[row] = col; 
			solve(row + 1);  
		}
	}
}

int main() {
	scanf("%d", &n);
	solve(0);
	printf("%d\n", result);
	return 0;
}

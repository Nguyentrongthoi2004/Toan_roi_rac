#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int matrix[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	
	int edgeCount = 0;
	int isDirected = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != matrix[j][i]) {
				isDirected = 1;
				break;
			}
		}
		if (isDirected) break;
	}
	
	if (!isDirected) {
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				edgeCount += matrix[i][j];
			}
		}
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				edgeCount += matrix[i][j];
			}
		}
	}
	
	printf("%d\n", edgeCount);
	
	return 0;
}

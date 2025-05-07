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
			int degree = 0;
			for (int j = 0; j < n; j++) {
				degree += matrix[i][j];
			}
			printf("%d", degree);
			if (i < n - 1) printf(";");
		}
	} else {
		for (int i = 0; i < n; i++) {
			int outDegree = 0;
			int inDegree = 0;
			for (int j = 0; j < n; j++) {
				outDegree += matrix[i][j];
				inDegree += matrix[j][i];
			}
			printf("%d", outDegree);
			if (i < n - 1) printf(";");
		}
		printf("\n");
		for (int i = 0; i < n; i++) {
			int outDegree = 0;
			int inDegree = 0;
			for (int j = 0; j < n; j++) {
				outDegree += matrix[i][j];
				inDegree += matrix[j][i];
			}
			printf("%d", inDegree);
			if (i < n - 1) printf(";");
		}
	}
	
	return 0;
}

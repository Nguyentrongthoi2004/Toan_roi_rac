#include <iostream>
using namespace std;

string checkGraphDirection(int n, int matrix[][100]) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (matrix[i][j] != matrix[j][i]) {
				return "co_huong";
			}
		}
	}
	return "vo_huong";
}

int main() {
	int n;
	cin >> n;
	
	int matrix[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	
	cout << checkGraphDirection(n, matrix) << endl;
	return 0;
}


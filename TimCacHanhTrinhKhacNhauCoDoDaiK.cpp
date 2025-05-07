#include <iostream>
#include <vector>
using namespace std;

int countPaths(const vector<vector<int>>& adjMatrix, int current, int end, int k) {
	if (k == 0) {
		return current == end ? 1 : 0;
	}
	
	int totalPaths = 0;
	for (int next = 0; next < adjMatrix.size(); next++) {
		if (adjMatrix[current][next] == 1) {
			totalPaths += countPaths(adjMatrix, next, end, k - 1);
		}
	}
	return totalPaths;
}

int main() {
	int n;
	cin >> n;
	
	vector<vector<int>> adjMatrix(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adjMatrix[i][j];
		}
	}
	
	int k, start, end;
	cin >> k >> start >> end;
	
	cout << countPaths(adjMatrix, start, end, k) << endl;
	
	return 0;
}


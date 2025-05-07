#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, const vector<vector<int>>& adjMatrix, vector<bool>& visited) {
	visited[node] = true;
	for (int i = 0; i < adjMatrix.size(); i++) {
		if (adjMatrix[node][i] == 1 && !visited[i]) { 
			DFS(i, adjMatrix, visited);
		}
	}
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
	
	vector<bool> visited(n, false); 
	DFS(0, adjMatrix, visited); 
	
	bool isConnected = true;
	for (bool nodeVisited : visited) {
		if (!nodeVisited) {
			isConnected = false;
			break;
		}
	}
	
	if (isConnected) {
		cout << "lien thong" << endl;
	} else {
		cout << "khong lien thong" << endl;
	}
	
	return 0;
}


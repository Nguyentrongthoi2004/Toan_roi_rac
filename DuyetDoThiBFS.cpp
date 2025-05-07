#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int start, const vector<vector<int>>& adjMatrix, vector<bool>& visited, vector<int>& result) {
	queue<int> q;
	
	visited[start] = true;
	q.push(start);
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		result.push_back(u);
		
		int n = adjMatrix.size();
		for (int v = 0; v < n; v++) {
			if (adjMatrix[u][v] && !visited[v]) {
				visited[v] = true;
				q.push(v);
			}
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
	
	int start;
	cin >> start;
	
	vector<bool> visited(n, false);
	vector<int> result;
	
	BFS(start, adjMatrix, visited, result);
	
	for (int v : result) {
		cout << v << " ";
	}
	cout << endl;
	
	return 0;
}

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(int start, const vector<vector<int>>& adjMatrix, vector<bool>& visited, vector<int>& result) {
	stack<int> s;
	s.push(start);
	
	while (!s.empty()) {
		int u = s.top();
		s.pop();
		
		if (!visited[u]) {
			visited[u] = true;
			result.push_back(u);
			
			for (int v = adjMatrix.size() - 1; v >= 0; v--) {
				if (adjMatrix[u][v] && !visited[v]) {
					s.push(v);
				}
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
	
	DFS(start, adjMatrix, visited, result);
	
	for (int v : result) {
		cout << v << " ";
	}
	return 0;
}


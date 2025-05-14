#include <iostream>
#define MAX 10
using namespace std;

void DFS(int graph[MAX][MAX], int n, bool visited[], int u) {
    visited[u] = true;
    for(int v = 0; v < n; v++) {
        if(graph[u][v] && !visited[v]) {
            DFS(graph, n, visited, v);
        }
    }
}

bool isConnected(int graph[MAX][MAX], int n) {
    bool visited[MAX] = {false};
    int startVertex = -1;
    for(int i = 0; i < n; i++) {
        int degree = 0;
        for(int j = 0; j < n; j++)
            degree += graph[i][j];
        if(degree > 0) {
            startVertex = i;
            break;
        }
    }
    if(startVertex == -1) return false;
    DFS(graph, n, visited, startVertex);
    for(int i = 0; i < n; i++) {
        int degree = 0;
        for(int j = 0; j < n; j++)
            degree += graph[i][j];
        if(degree > 0 && !visited[i])
            return false;
    }
    return true;
}

bool hasEulerCycle(int graph[MAX][MAX], int n){
    for(int i = 0; i < n; i++){
        int degree = 0;
        for(int j = 0; j < n; j++)
            degree += graph[i][j];
        if(degree % 2 != 0 || degree == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    int graph[MAX][MAX];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];

    if(hasEulerCycle(graph, n) && isConnected(graph, n))
        cout << "do_thi_Euler" << endl;
    else
        cout << "khong_phai_do_thi_Euler" << endl;
}//
// Created by nguye on 15/05/2025.
//

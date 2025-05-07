#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	if(!(cin >> n)) return 0;
	vector<vector<pair<int,int>>> adj(n);
	vector<ll> dist(n, INF);
	vector<int> prv(n, -1);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ll w;
			cin >> w;
			if(w > 0) 
				adj[i].emplace_back(j, (int)w);
		}
	}
	
	int s;
	cin >> s;
	
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
	dist[s] = 0;
	pq.emplace(0, s);
	
	while(!pq.empty()){
		auto [d, u] = pq.top(); 
		pq.pop();
		if(d != dist[u]) continue;
		for(auto &e : adj[u]){
			int v = e.first, w = e.second;
			if(dist[v] > d + w){
				dist[v] = d + w;
				prv[v] = u;
				pq.emplace(dist[v], v);
			}
		}
	}
	
	for(int v = 0; v < n; v++){
		if(dist[v] == INF) continue;
		cout << v << '|' << dist[v] << '|';
		vector<int> path;
		for(int x = v; x != -1; x = prv[x])
			path.push_back(x);
		reverse(path.begin(), path.end());
		for(int i = 0; i < (int)path.size(); i++){
			if(i) cout << "->";
			cout << path[i];
		}
		cout << '\n';
	}
	
	return 0;
}


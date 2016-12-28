#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y, s, dist[1123], visited[1123];
vector<int> graph[1123];

void bfs() {
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	dist[s] = 0;

	while (!q.empty()) {
		int u;
		u = q.front();
		q.pop();

		for (auto v : graph[u]) {
			if (!visited[v]) {
				q.push(v);
				visited[v] = 1;
				dist[v] = dist[u] + 6;
			}
		}
	}
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		
		for (int i = 1; i <= n; i++) {
			dist[i] = -1;
			visited[i] = 0;
			graph[i].clear();
		}

		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		cin >> s;

		bfs();

		// for (int i = 1; i <= n; i++) {
		// 	cout << dist[i] << " ";
		// }
		// cout << endl;


		for (int i = 1; i <= n; i++) {
			if (i != s) {
				cout << dist[i] << " ";
			}
		}
		cout << endl;
	}
}
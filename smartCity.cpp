#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > graph[1123456];
int n, m, k, u, v, w, dist[112345];
pair<int, int> tpair, tpair2;

void dijkstra(int source) {
	for(int i = 1; i <= 2 * n; i += 1) {
		dist[i] = -1;
	}
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, source));
	while(!q.empty()) {
		tpair = q.top();
		q.pop();
		int minimum_distance = -tpair.first;
		int current_node = tpair.second;
		if (dist[current_node] == -1) {
			dist[current_node] = minimum_distance;
			for(auto neighbour: graph[current_node]) {
				int _dist = neighbour.first;
				int next_node = neighbour.second;
				if (dist[next_node] == -1) {
					tpair2.first = -(minimum_distance + _dist);
					tpair2.second = next_node;
					q.push(tpair2);
				}
			}
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(w, v));
		graph[v].push_back(make_pair(w, u));
		graph[n + u].push_back(make_pair(w, n + v));
		graph[n + v].push_back(make_pair(w, n + u));
	}

	for (int i = 0; i < k; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(w, n + v));
	}

	dijkstra(1);
	cout << min(dist[n], dist[2 * n]) << endl;

}
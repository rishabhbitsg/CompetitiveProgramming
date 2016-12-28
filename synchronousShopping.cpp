#include <bits/stdc++.h>
using namespace std;

int n, m, k, x, y, z, t;
vector<int> fishType(1123);
vector< vector< pair<int, int> > > g(1123);
vector< vector<int> > dist(1123, vector<int>(1 << 11, -1));
priority_queue< pair< int, pair<int, int> > > h;

void dijkstra() {
	h.push(make_pair(0, make_pair(0, fishType[0])));
	while (!h.empty()) {
		pair<int, pair<int, int> > t = h.top();
		// cout << "current node = " << t.second.first << endl;
		h.pop();
		if (dist[t.second.first][t.second.second] == -1) {
			dist[t.second.first][t.second.second] = -t.first;
			// cout << dist[t.second.first][t.second.second] << endl;
			for (auto x : g[t.second.first]) {
				h.push(make_pair(t.first - x.second, make_pair
					(x.first, fishType[x.first] | t.second.second)));
			}
		}
	}
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		cin >> t;
		for (int j = 0; j < t; j++) {
			int temp;
			cin >> temp;
			fishType[i] |= 1 << (temp - 1);
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		g[x - 1].push_back(make_pair(y - 1, z));
		g[y - 1].push_back(make_pair(x - 1, z));
	}

	dijkstra();

	// for (auto x : dist) {
	// 	for (auto y : x) {
	// 		cout << y << " ";
	// 	}
	// 	cout << endl;
	// }
	int ans = INT_MAX;
	for (int i = 0; i < (1 << k); i++) {
		for (int j = 0; j < (1 << k); j++) {
			if ((i | j) == ((1 << k) - 1)) {
				if (dist[n - 1][i] != -1 && dist[n - 1][j] != -1) {
					// cout << "i = " << i << " j = " << j << " d1 = " << dist[n - 1][i]
				 // << " d2 = " << dist[n - 1][j] << endl;
					ans = min(ans, max(dist[n - 1][i], dist[n - 1][j]));
				}
			}
		}
	}

	cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int _distance[112345], special[11234], x, y, z, dist, n, m, k, result, currMin;
vector< pair<int, int> > graph[112345];
priority_queue< pair<int, int> > pq;
pair<int, int> tpair;

void dijkstra(int source) {
	pq.push(make_pair(0, source));
	while (!pq.empty()) {
		tpair = pq.top();
		pq.pop();
		x = tpair.second;
		dist = -tpair.first;
		if (_distance[x] == -1) {
			_distance[x] = dist;

			for (auto u : graph[x]) {
				if (_distance[u.second] == -1 && dist + u.first < currMin) {
					pq.push(make_pair(-(dist + u.first), u.second));
				}
			}
		}
	}

	for (int i = 0; i < k; i++) {
		if (_distance[special[i]] > 0) {
			currMin = min(currMin, _distance[special[i]]);
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> special[i];
		special[i]--;
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		graph[x - 1].push_back(make_pair(z, y - 1));
		graph[y - 1].push_back(make_pair(z, x - 1));
	}
	currMin = 1123456789;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			_distance[j] = -1;
		}

		dijkstra(special[i]);

		//_distance[special[i]] = 1123456789;
		/*for (int j = 0; j < n; j++) {
			cout << _distance[j] << " ";
		}
		cout << endl;
		*/
	}

	cout << currMin << endl;
}
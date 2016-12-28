#include <bits/stdc++.h>
using namespace std;

vector<int> graph[40], currVertices;
int n, m, cost[40], u, v, visited[40], ans, noWays;
bool present [40];
map <vector<int>, bool > presentVertices;

void solve(int currAns) {
	if (currAns > ans) {
		ans = currAns;
		sort(currVertices.begin(), currVertices.end());
		presentVertices[currVertices] = true;
		noWays = 1;
	}
	else if(currAns == ans) {
		sort(currVertices.begin(), currVertices.end());
		if (!(presentVertices[currVertices] == true)) {
			presentVertices[currVertices] = true;
			noWays++;
		}
	}
	for (int i = 1; i <= n; i++) {
		// cout << "i = " << i << " currAns = " << currAns << " cost[i] = " << cost[i] << " present[i] = " << present[i] << endl;
		if (!present[i]) {
			present[i] = true;
			vector<int> neighbours;
			for (auto x : graph[i]) {
				if (!present[x]) {
					present[x] = true;
					neighbours.push_back(x);
				}
			}
			currVertices.push_back(i);
			// cout << "----------------" << endl;
			// cout << "i = " << i << " currAns = " << currAns << " cost[i] = " << cost[i] << " present[i] = " << present[i] << endl;
			// cout << "----------------" << endl;
			solve(currAns + cost[i]); 
			present[i] = false;
			for (auto x : neighbours) {
				present[x] = false;
			}
			currVertices.erase(find(currVertices.begin(), currVertices.end(),
					i));
		} 
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> cost[i];
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		present[i] = false;
	}
	solve(0);

	cout << ans << " " << noWays << endl;
}
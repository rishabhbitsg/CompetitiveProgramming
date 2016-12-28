#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
vector< vector<int> > g(112);
vector<int> subSize(112);

int dfs(int node, int parent) {
	int temp = 1;
	for (auto x : g[node]) {
		if (x != parent) {
			temp += dfs(x, node);
		}
	}
	subSize[node] = temp;
	// cout << "node = " << node << " size = " << subSize[node] << endl;
	return subSize[node];
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0);
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (subSize[i] % 2 == 0) {
			ans += 1;
		}
	}

	cout << ans << endl;
}
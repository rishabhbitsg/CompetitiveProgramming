#include <bits/stdc++.h>
using namespace std;

int t, n, m, k1, k2, grid[112][112], visited[112][112], dist1[112][112], dist2[112][112];

void bfs(int sx, int sy, int dist[112][112], int visited[112][112], 
			vector< pair<int, int> > neighbour[112][112]) {

		queue< pair<int, int> > q;
		q.push(make_pair(sx, sy));
		int ans = -1;
		bool flag = false;
		visited[sx][sy] = 1;
		dist[sx][sy] = 0;
		while (!q.empty()) {
			pair<int, int> current = q.front();
			q.pop();
			
			for (auto x : neighbour[current.first][current.second]) {
					
				if (visited[x.first][x.second]) continue;
				

				// printf("state reached %d %d \n", 
				// 	x.first, x.second);
				visited[x.first][x.second] = 1;
		
				 dist[x.first][x.second] = 
				 	dist[current.first][current.second] + 1;
				q.push(x);	
			}
			
		}
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m >> k1 >> k2;
		vector< pair<int, int> > neighbour1[112][112], neighbour2[112][112];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 0) {
					for (int a = -k1; a <= k1; a++) {
						for (int b = abs(a) - k1; b <= k1 - abs(a); b++) {
							if (i + a < 0 || i + a > n) continue;
							if (j + b < 0 || j + b > m) continue;
							if (grid[a + i][b + j] == 1) continue;
							neighbour1[i][j].push_back(make_pair(a + i, b + j));
						}
					}
					for (int a = -k2; a <= k2; a++) {
						for (int b = abs(a) - k2; b <= k2 - abs(a); b++) {
							if (i + a < 0 || i + a > n) continue;
							if (j + b < 0 || j + b > m) continue;
							if (grid[a + i][b + j] == 1) continue;
							neighbour2[i][j].push_back(make_pair(a + i, b + j));
						}
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = 0;
				dist1[i][j] = -1;
			}
		}


		bfs(0, 0, dist1, visited, neighbour1);


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = 0;
				dist2[i][j] = -1;
			}
		}

		bfs(0, m - 1, dist2, visited, neighbour2);

		int ans = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// printf("i = %d, j = %d, dist1[i][j] = %d, dist2[i][j] = %d, ans = %d\n"
				// 			, i, j, dist1[i][j], dist2[i][j], ans);
				if (dist1[i][j] != -1 && dist2[i][j] != -1) {
					if (max(dist1[i][j], dist2[i][j]) < ans || ans == -1) {
						ans = max(dist1[i][j], dist2[i][j]);
					}
				}
			}
		}
		cout << ans << endl;
	}
}
#include <bits/stdc++.h>
using namespace std;

int t, r, c, h[60][60], visited[60][60];

int main() {
	cin >> t;
	int x = 1;
	while (t--) {
		int ans = 0;
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> h[i][j];
				visited[i][j] = 0;
			}
		}

		for (int i = 1; i < r - 1; i++) {
			for (int j = 1; j < c - 1; j++) {
				if (!visited[i][j]) {
					visited[i][j] = 1;
					stack< pair<int, int> > s;
					vector<int> heights;


					s.push(make_pair(i, j));
					heights.push_back(h[i][j]);
					bool flag = true;
					int borderMin = INT_MAX;


					while(!s.empty()) {								
						pair<int, int> p = s.top();
						s.pop();
						// cout << "p.first = " << p.first << " p.second = " << p.second << endl; 
						if (p.first == 1 && h[p.first][p.second] >= h[p.first - 1][p.second]) {
							flag = false;
						}
						else if (!visited[p.first - 1][p.second] && h[p.first][p.second] >= h[p.first - 1][p.second]) {
							visited[p.first - 1][p.second] = 1;
							s.push(make_pair(p.first - 1, p.second));
							heights.push_back(h[p.first - 1][p.second]);
						}
						else if (!visited[p.first - 1][p.second] && h[p.first][p.second] < h[p.first - 1][p.second]) {
							borderMin = min(borderMin, h[p.first - 1][p.second]); 
						}


						if (p.second == 1 && h[p.first][p.second] >= h[p.first][p.second - 1]) {
							flag = false;
						}
						else if (!visited[p.first][p.second - 1] && h[p.first][p.second] >= h[p.first][p.second - 1]) {
							visited[p.first][p.second - 1] = 1;
							s.push(make_pair(p.first, p.second - 1));
							heights.push_back(h[p.first][p.second - 1]);
						}
						else if (!visited[p.first][p.second - 1] && h[p.first][p.second] < h[p.first][p.second - 1]) {
							borderMin = min(borderMin, h[p.first][p.second - 1]); 
						}



						if (p.first == r - 2 && h[p.first][p.second] >= h[p.first + 1][p.second]) {
							flag = false;
						}
						else if (!visited[p.first + 1][p.second] && h[p.first][p.second] >= h[p.first + 1][p.second]) {
							visited[p.first + 1][p.second] = 1;
							s.push(make_pair(p.first + 1, p.second));
							heights.push_back(h[p.first + 1][p.second]);
						}
						else if (!visited[p.first + 1][p.second] && h[p.first][p.second] < h[p.first + 1][p.second]) {
							borderMin = min(borderMin, h[p.first + 1][p.second]); 
						}



						if (p.second == c - 2 && h[p.first][p.second] >= h[p.first][p.second + 1]) {
							flag = false;
						}
						else if (!visited[p.first][p.second + 1] && h[p.first][p.second] >= h[p.first][p.second + 1]) {
							visited[p.first][p.second + 1] = 1;
							s.push(make_pair(p.first, p.second + 1));
							heights.push_back(h[p.first][p.second + 1]);
						}
						else if (!visited[p.first][p.second + 1] && h[p.first][p.second] < h[p.first][p.second + 1]) {
							borderMin = min(borderMin, h[p.first][p.second + 1]); 
						}

						// cout << "borderMin = " << borderMin << endl;
					}

					// cout << "Exited" << endl;
					// cout << "flag = " << flag << endl;
					if (flag) {
						for (auto x : heights) {
							ans += borderMin - x;
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n", x++, ans);
	}
}
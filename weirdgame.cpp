#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int t, n, m;

int main() {
	cin >> t;
	while (t--) {
		int score = 0;
		cin >> n >> m;
		bool marked[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i > 0 && marked[i - 1][j]) score++;
				if (j > 0 && marked[i][j - 1]) score++;
				marked[i][j] = true;
			}
		}
		cout << score << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int likes[m][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;
				likes[j][i] = c - '0';
			}
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			int noOfBoys = accumulate(likes[i], likes[i] + n, 0);
			// printf("i = %d and noOfBoys = %d\n", i, noOfBoys);
			ans += noOfBoys * (noOfBoys - 1)  / 2;
		}

		cout << ans << endl;
	}
}
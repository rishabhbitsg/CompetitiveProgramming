#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
int n, m, a[21234], b[11234], dp[21234][11234];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		dp[i][1] = 1;
	}

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 2; k <= m; k++) {
				if (a[i] + b[k - 1] >= a[j] + b[k - 2]) {
					/*if (k == m) {
						cout << a[i] + b[k - 1] << " " << a[j] + b[k - 2] << endl; 
					}*/
					dp[i][k] = (dp[i][k] + dp[j][k - 1]) % M;
				}
			}
		}
	}

	long long result = 0;
	for (int i = 0; i < n; i++) {
		// cout << dp[i][m] << " ";
		result = (result + dp[i][m]) % M;
	}
	// cout << endl;

	cout << result << endl;
}
#include <bits/stdc++.h>
using namespace std;

int a, b, n, dp[30];

int main() {
	cin >> a >> b >> n;
	dp[0] = a;
	dp[1] = b;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] * dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] << endl;
}
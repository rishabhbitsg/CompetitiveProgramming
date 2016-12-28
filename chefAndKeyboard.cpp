#include <bits/stdc++.h>
using namespace std;

int t, n, m, c;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m >> c;

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (c % i == 0 && c / i <= m) {
				ans += 1;
			}
		}

		cout << ans << endl;
	}
}
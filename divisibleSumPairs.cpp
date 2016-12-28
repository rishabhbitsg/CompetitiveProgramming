#include <bits/stdc++.h>
using namespace std;

int n, k, a[112], ans;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((a[i] + a[j]) % k == 0) ans++;
		}
	}

	cout << ans << endl;
}
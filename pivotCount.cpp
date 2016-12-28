#include <bits/stdc++.h>
using namespace std;

int hi[112345], lo[112345], a[112345], n, cmax, cmin, ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cmax = a[0];
	hi[0] = cmax;
	for (int i = 1; i < n; i++) {
		cmax = max(cmax, a[i]);
		hi[i] = cmax; 
	}
	cmin = a[n - 1];
	lo[n - 1] = cmin;
	for (int i = n - 2; i >= 0; i--) {
		cmin = min(cmin, a[i]);
		lo[i] = cmin;
	}

	for (int i = 0; i < n; i++) {
		if (hi[i] <= a[i] && a[i] <= lo[i]) ans++; 
	}

	cout << ans << endl;
}

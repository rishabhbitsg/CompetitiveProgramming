#include <bits/stdc++.h>
using namespace std;

long long M = 1000000007;

long long t, n, oldN, k, a[112345];

long long fast_pow(long long base, long long n, long long M) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return base;
	}
	long long halfN = fast_pow(base, n / 2, M);
	if (n % 2 == 0) {
		return (halfN * halfN) % M;
	}
	else {
		return (((halfN * halfN) % M) * base) % M;
	}
}

long long mmi(long long a, long long M) {
	return fast_pow(a, M - 2, M);
}

int main() {
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		oldN = n;
		for (int i = 0; i < oldN; i++) {
			if (a[i] == 0) n--;
		}
		//cout << "n = " << n << endl;
		if (n == 0) cout << 1 << endl;
		else if (n < oldN) {
			long long ans[n + 1];
			ans[0] = 1;
			ans[n] = ans[0];
			for (int i = 1; i < n / 2 + 2; i++) {
				ans[i] = (((ans[i - 1] % M) * ((n + 1 - i) % M) % M) * (mmi(i, M) % M)) % M;
				ans[n - i] = ans[i];
			}
			for (int i = 1; i <= n; i++) {
				ans[i] = ((ans[i] % M) + (ans[i - 1] % M)) % M;
			}

			if (k > n) {
				cout << ans[n] << endl;
			}
			else {
				cout << ans[k] << endl;
			}
		}
		else {
			long long ans[n + 1];
			ans[0] = 1;
			ans[n] = ans[0];
			for (int i = 1; i < n / 2 + 2; i++) {
				ans[i] = (((ans[i - 1] % M) * ((n + 1 - i) % M) % M) * (mmi(i, M) % M)) % M;
				ans[n - i] = ans[i];
			}
			for (int i = 2; i <= n; i++) {
				ans[i] = ((ans[i] % M) + (ans[i - 2] % M)) % M;
			}
			/*
			for (int i = 0; i <= n; i++) {
				cout << ans[i] << " ";
			}*/
			//cout << endl;
			if (k > n) {
				if (k % 2 == 0) {
					if (n % 2 == 0) {
						cout << ans[n] << endl;
					}
					else {
						cout << ans[n - 1] << endl;
					}	
				}
				else {
					if (n % 2 == 0) {
						cout << ans[n - 1] << endl;
					}
					else {
						cout << ans[n] << endl;
					}	
				}
			}
			else {
				cout << ans[k] << endl;
			}	
		}

	}
}
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
int t, n, a[751234];

int main() {
	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		sort(a, a + n);

		unordered_map <int, int> m;
		for (int i = 0; i < n; i++) {
			m[a[i]] = i;
		}

		int i = n - 1;
		int ans[n];
		while (i >= 0) {
			int curr = a[i];
			ans[i] = 1;
			for (int j = curr * 2; j <= 751234; j += curr) {
				if (m.find(j) != m.end()) {
					ans[i] = (ans[i] + ans[j]) % M;
				}
			}
			i -= 1;
		}

		int fAns = 0;
		for (int i = 0; i < n; i++) {
			fAns = (fAns + ans[i]) % M;
		}

		cout << fAns << endl;
	}
}
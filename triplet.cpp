#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int l, m, n, temp;
		long long ans;
		vector<int> a, b, c;
		cin >> l;
		ans = 0;
		for (int i = 0; i < l; i++) {
			cin >> temp;
			a.push_back(temp);
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> temp;
			b.push_back(temp);
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			c.push_back(temp);
		}

		for (int i = 0; i < m; i++) {
			long long ans1, ans2;
			vector<int> :: iterator lo, hi;
			lo = upper_bound(a.begin(), min(a.begin() + i + 1, a.end()), b[i]);
			hi = lower_bound(min(c.begin() + i, c.end()), c.end(), b[i]);
			ans1 = lo - a.begin();
			ans2 = c.end() - hi;
			//cout << "ans1 = " << ans1 << " ans2 = " << ans2 << endl;
			ans += ans1 * ans2;
		}

		cout << ans << endl;
	}
}
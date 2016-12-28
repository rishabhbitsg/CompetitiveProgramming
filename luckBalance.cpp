#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
vector<int> important;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int l, t;
		cin >> l >> t;
		if (t) important.push_back(-l);
		else ans += l;
	}
	sort(important.begin(), important.end());
	int i;
	for (i = 0; i < min(int(important.size()), k); i++) {
		ans += -important[i];
	}
	for (; i < important.size(); i++) {
		ans += important[i];
	}
	cout << ans << endl;
}
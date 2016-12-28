#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n, a;
long long ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			vector<int> :: iterator lo;
			int tempAns;
			lo = lower_bound(v.begin() + j + 1, v.end(), v[i] + v[j]);
				lo--;
			tempAns = (lo - (v.begin() + j));
			//cout << tempAns << endl;
			ans += tempAns;
		}
	}

	cout << ans << endl;
}
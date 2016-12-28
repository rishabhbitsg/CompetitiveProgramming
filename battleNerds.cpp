#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n, a, q, s, lo, hi, dis1, dis2;
double l;

int main() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < q; i++) {
		cin >> s >> l;
		vector<int> :: iterator it1, it2;
		it1 = lower_bound(v.begin(), v.end(), s);
		it2 = upper_bound(v.begin(), v.end(), s);
		lo = *it1;
		hi = *it2;
		if (it1 == v.end()) {
			lo = v[n - 1];
		} 
		else if (lo != s) {
			lo = *(it1 - 1);
		}
		if (it2 == v.end()) {
			hi = v[n - 1];
		}

		// cout << "lo = " << lo << " hi = " << hi << endl;
		dis1 = (s - lo) * 2;
		dis2 = (hi - s) * 2;
		if (dis1 <= l || dis2 <= l) {
			if (dis1 <= dis2) {
				cout << lo << endl;
			}
			else {
				cout << hi << endl;
			}
		}
		else {
			cout << -1 << endl;
		}
	}
}
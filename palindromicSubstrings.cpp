#include <bits/stdc++.h>
using namespace std;

int t, a_mask, b_mask;
string a, b;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		a_mask = b_mask = 0;

		for (int j = 0; j < a.size(); j++) {
			a_mask |= 1 << a[j] - 'a';
		}
		for (int j = 0; j < b.size(); j++) {
			b_mask |= 1 << b[j] - 'a';
		}

		cout << (a_mask & b_mask ? "Yes" : "No") << endl;
	}
}	
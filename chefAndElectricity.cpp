#include <bits/stdc++.h>
using namespace std;

string s;
int n, t, a[112345], _left[112345], _right[112345];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> s;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		

		int currLeft = -INT_MAX;
		// cout << "---------------LEFT---------------" << endl;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				_left[i] = currLeft;
			}
			else {
				currLeft = a[i];
				_left[i] = currLeft;
			}
			// cout << _left[i] << " ";
		}
		// cout << endl;

		int currRight = INT_MAX;
		// cout << "---------------RIGHT---------------" << endl;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '0') {
				_right[i] = currRight;
			}
			else {
				currRight = a[i];
				_right[i] = currRight; 
			}
			// cout << _right[i] << " ";
		}
		// cout << endl;

		int ans, localAns;
		localAns = INT_MAX;
		ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1' && localAns != INT_MAX) {
				// cout << "i = " << i << " localAns = " << localAns << endl;
				ans += localAns;
				localAns = INT_MAX;
			}
			else if (i == 0 && s[i] == '0') {
				localAns = _right[i] - a[i];
			}
			else if (i == n - 1 && s[i] == '0') {
				localAns = a[i] - _left[i];
			}
			else if (s[i] == '0') {
				if (_left[i] != -INT_MAX &&  _right[i] != INT_MAX) {
					localAns = min(localAns, a[i] - _left[i] + _right[i + 1] - a[i + 1]);
					localAns = min(localAns, a[i - 1] - _left[i] + _right[i] - a[i]);
				}
			}
		}

		if (localAns != INT_MAX) {
			ans += localAns;
		}

		cout << ans << endl;
	}
}
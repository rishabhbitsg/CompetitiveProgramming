#include <bits/stdc++.h>
using namespace std;

int t, n, k;
long long a[112345], b[112345], mneg, mpos;
long long result;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		for (int j = 0; j < n; j++) {
			cin >> b[j];
		}
		result = 0;
		mneg = mpos = 0;
		for (int j = 0; j < n; j++) {
			if (b[j] > mpos) {
				mpos = b[j];
			}
			else if (b[j] < mneg) {
				mneg = b[j];
			}
			result += b[j] * a[j];
		}
		// cout << "mpos = " << mpos << " mneg = " << mneg << endl;
		// cout << "result = " << result << endl;
		if (mpos < -mneg) {
			result += (-mneg * k); 
		}
		else {
			result += (mpos * k);
		}

		cout << result << endl;
	}
}
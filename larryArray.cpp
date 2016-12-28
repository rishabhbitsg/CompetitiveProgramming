#include <bits/stdc++.h>
using namespace std;

int t, n, a[1123], noOfInversions;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		noOfInversions = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i - 1; j >= 0; j--) {
				if (a[i] < a[j]) noOfInversions++;
			}
		}

		if (noOfInversions % 2 == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}
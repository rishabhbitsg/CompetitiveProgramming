#include <bits/stdc++.h>
using namespace std;

long long t, n, m;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		if ((n % 2 == 0 || m % 2 == 0) && n != 1 && m != 1) {
			cout << "Yes" << endl;
		}
		else if (n * m == 2) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
} 
#include <bits/stdc++.h>
using namespace std;

int t, r, g, b, k;
long long result;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> r >> g >> b;
		cin >> k;
		result = ((long long)min(k - 1, r) + min(k - 1, b) + min(k - 1, g)) + 1;
		cout << result << endl;
	}
}
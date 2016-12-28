#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a[11];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << accumulate(a, a + n, ll(0)) << endl;
}
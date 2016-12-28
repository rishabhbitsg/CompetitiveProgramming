#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll factorial[22], n, a[22], freq[111];

void compute() {
	factorial[0] = 1;
	for (ll i = 1; i <= 18; i++) {
		factorial[i] = factorial[i - 1] * i;
	}
}

int main() {
	compute();

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		freq[a[i]]++;
	}


	ll ans = factorial[n];
	for (int i = 1; i <= 100; i++) {
		ans /= factorial[freq[i]];
	}

	cout << ans << endl;	
}

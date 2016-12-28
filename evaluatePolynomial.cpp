#include <bits/stdc++.h>
using namespace std;
#define M 786433
int n, q, x, a[251234];

long long solve(int x) {
	long long result = a[n];
	for (int i = n - 1; i >= 0; i--) {
		result = (a[i] % M + (result * x) % M) % M;
	}
	return result;
}

int main() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> x;
		cout << solve(x) << endl;
	}
}
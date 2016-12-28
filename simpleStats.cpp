#include <bits/stdc++.h>
using namespace std;

int t, n, k, a[11234];
float result;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;

		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}

		sort(a, a + n);
		result = 0;
		for (int j = k; j < n - k; j++) {
			result += a[j];
		}

		result = result / (n - 2 * k);
		printf("%.6f\n", result);
	}
}
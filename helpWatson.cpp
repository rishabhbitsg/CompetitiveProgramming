#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
long long n, k, t, result;

long long exp(long long a, long long b) {
	if (b == 1) return a;
	if (b == 0) return 1;

	if (b % 2 == 0) return ((exp(a, b / 2) % M) * (exp(a, b / 2) % M)) % M;
	else return ((((exp(a, b / 2) % M) * (exp(a, b / 2) % M)) % M) * (a % M)) % M;
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		result = exp(k - 1, n - 1);
		result = (result * (k % M)) % M;
		cout << result << endl;
	}
}
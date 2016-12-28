#include <bits/stdc++.h>
using namespace std;

long long res, a, m, n;

int main() {
	cin >> n >> m >> a;
	if (n % a) res = n / a + 1;
	else res = n / a;
	if (m % a) res *= m / a + 1;
	else res *= m / a;
	cout << res << endl;
}
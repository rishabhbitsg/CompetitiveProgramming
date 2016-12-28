#include <bits/stdc++.h>
using namespace std;

long long n, lo, hi, mid;

int main() {
	cin >> n;
	lo = 0;
	hi = n;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (pow(mid, 2) < n) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
		//cout << "lo = " << lo << " hi = " << hi << " mid * mid = " << 
		//mid * mid << endl;
	}

	cout << lo << endl;
}

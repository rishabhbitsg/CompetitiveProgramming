#include <bits/stdc++.h>
using namespace std;

int a[112345], n, k;
long long ans;

int partition(int *, int, int);
void smallest(int *, int, int, int);

void smallest(int * a, int lo, int hi, int r) {
	int p = partition(a, lo, hi);
	//cout << "p = " << p << endl;
	if (p < r) smallest(a, p + 1, hi, r);
	else if (p > r) smallest(a, lo, p - 1, r);
}

int partition(int * a, int lo, int hi) {
	int i, j;
	i = lo;
	//cout << "pivot = " << a[hi] << endl;
	ans += a[hi];
	for (int j = lo; j <= hi - 1; j++) {
		if (a[j] < a[hi]) {
			swap(a[i], a[j]);
			i++;
		}
	}	
	swap(a[hi], a[i]);
	return i;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	smallest(a, 0, n - 1, k);
	cout << ans << endl;
}
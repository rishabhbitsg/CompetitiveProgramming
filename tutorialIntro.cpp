#include <bits/stdc++.h>
using namespace std;

int v, n, arr[1123];

int main() {
	cin >> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = lower_bound(arr, arr + n, v) - arr;
	cout << ans << endl;
}
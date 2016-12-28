#include <bits/stdc++.h>
using namespace std;

int a, b, n, ans;

int main() {
	cin >> n >> a >> b;
	ans = (a + b) % n;
	if (ans > 0) cout << ans << endl;
	else if (ans < 0) cout << n + ans << endl;
	else cout << n << endl;
}
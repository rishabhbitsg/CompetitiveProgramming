#include <bits/stdc++.h>
using namespace std;

int t;
double v, s;

int main() {
	cin >> t;
	while (t--) {
		cin >> s >> v;
		double ans;
		ans = (2 * s) / (3 * v);
		printf("%.12lf\n", ans);
	}
}
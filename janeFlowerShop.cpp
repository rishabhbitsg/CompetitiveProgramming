#include <bits/stdc++.h>
using namespace std;

int t, m, income[112];

double f(double r) {
	double result = 0;
	for (int i = 0; i < m; i++) {
		result += income[m - i] * pow(r, i);
	}
	result += -1 * income[0] * pow(r, m);
	return result;
}

double fd(double r) {
	double result = 0;
	for (int i = 1; i < m; i++) {
		result += i * income[m - i] * pow(r ,i - 1);
	}
	result += -m * income[0] * pow(r, m - 1);
	return result;
}

int main() {
	cin >> t;
	for (int x = 1; x <= t; x++) {
		cin >> m;
		for (int i = 0; i <= m; i++) {
			cin >> income[i];
		}

		double ans = 0;
		int counter = 0;
		while (abs(f(ans)) >= 1e-9) {
			cout << "ans = " << ans << " f(a) = " << f(ans) << " fd(a) = " << fd(ans) << "f(a) / fd(a) = " << f(ans) / fd(ans) << endl;
			printf("%.12lf\n", ans);
			ans = ans - f(ans) / fd(ans);
			// cout << ans << endl;
			counter++;
		}

		cout << ans << endl;
	}
}
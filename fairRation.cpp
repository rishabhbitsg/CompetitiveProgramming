#include <bits/stdc++.h>
using namespace std;

int n, a[1123], noEven, noOdd;
bool marked[1123];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0 && flag) {
			noOdd++;
			flag = false;
		}
		else if (a[i] % 2 == 0 && !flag) {
			noEven++;
		}
		else if (a[i] % 2 != 0 && !flag) {
			noOdd++;
			flag = true;
		}
	}

	if (noOdd % 2 == 0) {
		cout << 2 * noEven + noOdd << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
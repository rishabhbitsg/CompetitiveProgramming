#include <bits/stdc++.h>
using namespace std;

long long t, n, a[11234], b[11234], marked[11234];
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		long long c = 0;
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			c += b[i];
			marked[i] = false;
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			c += a[i];
		}
		if (c % n == 0) {
			bool flag = true;
			c /= n;
			for (int i = 0; i < n; i++) {
				if (a[i] == c) continue;
				else if (i > 0 && !marked[i - 1] && a[i] + b[i - 1] == c) {
					marked[i - 1] = true;
				}
				else if (!marked[i] && a[i] + b[i] == c) {
					marked[i] = true;
				}
				else if (i < n - 1 && !marked[i + 1] && a[i] + b[i + 1] == c) {
					marked[i + 1] = true;
				}
				else if (i > 0 && !marked[i - 1] && !marked[i] && a[i] + b[i - 1] + b[i] == c) {
					marked[i] = marked[i - 1] = true;
				}
				else if (i > 0 && i < n - 1 && !marked[i - 1] && !marked[i + 1] && a[i] + b[i - 1] + b[i + 1] == c) {
					marked[i - 1] = marked[i + 1] = true;
				}
				else if (i < n - 1 && !marked[i + 1] && !marked[i] && a[i] + b[i + 1] + b[i] == c) {
					marked[i] = marked[i + 1] = true;
				}
				else if (i > 0 && i < n - 1 && !marked[i + 1] && !marked[i - 1] && !marked[i] && a[i] + b[i + 1] + b[i - 1] + b[i] == c) {
					marked[i] = marked[i - 1] = marked[i + 1] = true;
				}
				else {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << c << endl;
			}
			else {
				bool flag = true;
				for (int i = 0; i < n; i++) {
					marked[i] = false;
				}
				for (int i = n - 1; i >= 0; i--) {
					if (a[i] == c) continue;
					
					else if (i < n - 1 && !marked[i + 1] && a[i] + b[i + 1] == c) {
						marked[i + 1] = true;
					}
					else if (!marked[i] && a[i] + b[i] == c) {
						marked[i] = true;
					}
					else if (i > 0 && !marked[i - 1] && a[i] + b[i - 1] == c) {
						marked[i - 1] = true;
					}
					

					else if (i < n - 1 && !marked[i + 1] && !marked[i] && a[i] + b[i + 1] + b[i] == c) {
						marked[i] = marked[i + 1] = true;
					}
					else if (i > 0 && i < n - 1 && !marked[i - 1] && !marked[i + 1] && a[i] + b[i - 1] + b[i + 1] == c) {
						marked[i - 1] = marked[i + 1] = true;
					}
					else if (i > 0 && !marked[i - 1] && !marked[i] && a[i] + b[i - 1] + b[i] == c) {
						marked[i] = marked[i - 1] = true;
					}

					else if (i > 0 && i < n - 1 && !marked[i + 1] && !marked[i - 1] && !marked[i] && a[i] + b[i + 1] + b[i - 1] + b[i] == c) {
						marked[i] = marked[i - 1] = marked[i + 1] = true;
					}
					else {
						flag = false;
						break;
					}
				}
				if (flag) cout << c << endl;
				else cout << -1 << endl;
			}

		}
		else {
			cout << -1 << endl;
		}
	}
		
} 	
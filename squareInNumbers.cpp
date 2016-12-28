#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int t, n;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool is_perfect_square(ll n) {
    if (n < 0)
        return false;
    ll root = (round(sqrt(n)));
    return n == root * root;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		ll numbers[n];
		for (int i =  0; i < n; i++) {
			cin >> numbers[i];
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (is_perfect_square(numbers[i])) {
				cout << sqrt(numbers[i]) << endl;
				flag = false;
				break;
			}
		}

		if (flag) {
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					ll p = gcd(numbers[i], numbers[j]);
					if (p > 1) {
						cout << p << endl;
						break;
					}
				}
			}
		}
	}
}
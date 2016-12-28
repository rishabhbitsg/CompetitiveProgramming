#include <bits/stdc++.h>
using namespace std;

long long n, m;
int t;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << (max(n, m) - min(n, m)) << endl;
	}
}


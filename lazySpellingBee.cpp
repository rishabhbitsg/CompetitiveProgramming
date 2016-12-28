#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

int t, x;
string a;

int main() {
	cin >> t;
	while (t--) {
		x++;
		long long ans = 1;
		cin >> a;
		if (a.size() > 1) {
			for (int i = 0; i < a.size(); i++) {
				if (i == 0) {
					ans = ans * (a[i] == a[i + 1] ? 1 : 2) % M;
				}
				else if (i == a.size() - 1) {
					ans = ans * (a[i] == a[i - 1] ? 1 : 2) % M;
				}
				else {
					if (a[i] == a[i - 1]) {
						if (a[i] != a[i + 1]) ans = ans * 2 % M;
					}
					else if (a[i] == a[i + 1]) {
						ans = ans * 2 % M;
					}
					else if (a[i - 1] == a[i + 1]) {
						ans = ans * 2 % M;
					}
					else ans = ans * 3 % M;
				}
			}	
		}
		
		printf("Case #%d: %lld\n", x, ans);
	}
}
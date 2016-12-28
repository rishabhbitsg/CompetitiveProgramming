#include <bits/stdc++.h>
using namespace std;

int n, a[3123]; 

int main() {
	while (cin >> n) {
		bool mask[n];
		for (int i = 0; i < n; i++)
			mask[i] = false;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 1; i < n; i++) {
			if (abs(a[i] - a[i - 1]) < n)
				mask[abs(a[i] - a[i - 1])] = true;
		}
		bool flag = true;
		for (int i = 1; i <= n - 1; i++) {
			if (!mask[i]) {
				flag = false;
				break;
			}
		} 
		if (flag) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;	
	}
}
#include <bits/stdc++.h>
using namespace std;

int t, n, noR, noG, noB;
string s;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cin >> s;
		noR = noB = noG = 0;
		for (int j = 0; j < n; j++) {
			switch (s[j]) {
				case 'R': 
					noR ++;
					break;
				case 'G':
					noG++;
					break;
				case 'B':
					noB++;
					break;
				default:
					break;
			};
		}

		cout << n - max(noR, max(noG, noB)) << endl;
	}	
}
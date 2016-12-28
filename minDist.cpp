#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> indexMap;
int n, a[1123];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (indexMap.find(a[i]) == indexMap.end()) {
			indexMap[a[i]] = i;
		}
		else {
			ans = min(i - indexMap[a[i]], ans);
			indexMap[a[i]] = i;
		}
	}
	cout << (ans == INT_MAX ? -1 : ans) << endl;
}
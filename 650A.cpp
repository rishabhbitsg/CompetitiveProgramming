#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> countEqual;
unordered_map< pair<int, int>, int > countEqual2;
int n, x, y, result;
pair<int, int> loc[212345];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		loc[i] = make_pair(x, y);
	}

	for (int i = 0; i < n; i++) {
		if (countEqual.find(loc[i].first) == countEqual.end()) {
			countEqual[loc[i].first] = 1;
		}
		else {
			countEqual[loc[i].first]++;
		}
	}

	for (auto x : countEqual) {
		if (x.second > 1) {
			result += ((x.second * (x.second - 1)) / 2);
		}
	}

	countEqual.clear();

	for (int i = 0; i < n; i++) {
		if (countEqual.find(loc[i].second) == countEqual.end()) {
			countEqual[loc[i].second] = 1;
		}
		else {
			countEqual[loc[i].second]++;
		}
	}

	for (auto x : countEqual) {
		if (x.second > 1) {
			result += ((x.second * (x.second - 1)) / 2);
		}
	}

	for (int i = 0; i < n; i++) {
		if (countEqual2.find(loc[i]) == countEqual2.end()) {
			countEqual2[loc[i]] = 1;
		}
		else {
			countEqual2[loc[i]]++;
		}
	}

	for (auto x : countEqual2) {
		if (x.second > 1) {
			result -= ((x.second * (x.second - 1)) / 2);
		}
	}	

	cout << result << endl;
}
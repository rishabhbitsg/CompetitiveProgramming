#include <bits/stdc++.h>
using namespace std;

int n, m, ans, a, current, currBal;
map<int, int> alreadyHas;
vector<int> canTake;

int main() {
	cin >> n >> m;
	currBal = m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		alreadyHas[a] = 1;
	}

	current = 1;
	while (currBal > 0) {
		if (alreadyHas[current]) current++;
		else if (currBal - current >= 0) {
			currBal -= current;
			canTake.push_back(current);
			current++;
		}
		else {
			break;
		} 
	}

	cout << canTake.size() << endl;
	for (auto x : canTake) {
		cout << x << " ";
	}
	cout << endl;
}
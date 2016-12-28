#include <bits/stdc++.h>
using namespace std;

class ZigZag {
public:
	int longestZigZag(vector<int> sequence) {
		int n = sequence.size();
		int result[2][n];
		fill(result[0], result[0] + n, 1);
		fill(result[1], result[1] + n, 1);
		int currMax = 1;
		for (int i = 1; i < sequence.size(); i++) {
			for (int j = 0; j < i; j++) {
				int diff = sequence[i] - sequence[j];
				// cout << "diff = " << diff << " sign = " << sign << endl;
				if (diff) {
					if (diff > 0)
						result[0][i] = max(result[1][j] + 1, result[0][i]);
					if (diff < 0)
					result[1][i] = max(result[0][j] + 1, result[1][i]);
				}

				/*for (int k = 0; k < sequence.size(); k++) {
					cout << "( " << result[k].first << ", " << result[k].second << "), ";
				}
				cout << endl;
				*/
			}
			currMax = max(result[0][i], currMax);
			currMax = max(result[1][i], currMax);
		}

		return currMax;
	}
};


/*int main() {
	int a[] = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
	vector<int> v(a, a + 10);

	ZigZag z;
	cout << z.longestZigZag(v) << endl; 
}*/
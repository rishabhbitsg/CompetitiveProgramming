#include <bits/stdc++.h>
using namespace std;

class BadNeighbors {
public:
	int maxDonations(vector<int> donations) {
		int n = donations.size();
		int result[n], maxSum;

		result[0] = donations[0];
		result[1] = max(donations[0], donations[1]);
		maxSum = result[1];
		for (int i = 2; i < n - 1; i++) {
			result[i] = max(result[i - 1], result[i - 2] + donations[i]);
			maxSum = max(result[i], maxSum);
		}

		result[n - 1] = donations[n - 1];
		result[n - 2] = max(donations[n - 1], donations[n - 2]);
		for (int i = n - 3; i > 0; i--) {
			result[i] = max(result[i + 1], result[i + 2] + donations[i]);
			maxSum = max(result[i], maxSum);
		} 

		return maxSum;
	}
};
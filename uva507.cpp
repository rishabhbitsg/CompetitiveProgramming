#include <bits/stdc++.h>
using namespace std;

int niceness[21234];

int main() {
	int b, s;
	cin >> b;
	for (int r = 1; r <= b; r++) {
		cin >> s;
		for (int i = 1; i <= s - 1; i++) {
			cin >> niceness[i];
		}

		int ansStart, ansEnd, start, currSum, maxSum;
		start = 1;
		maxSum = INT_MIN;
		currSum = 0;
		for (int i = 1; i <= s - 1; i++) {
			currSum += niceness[i];
			if (maxSum < currSum) {
				maxSum = currSum;
				ansStart = start;
				ansEnd = i + 1;
			} 
			else if (maxSum == currSum) {
				if (ansEnd - ansStart < i + 1 - start) {
					maxSum = currSum;
					ansStart = start;
					ansEnd = i + 1;		
				}
			}
			if (currSum < 0) {
				start = i + 1;
				currSum = 0;
			}
		}

		if (maxSum >= 0)
			printf("The nicest part of route %d is between stops %d and %d\n", r, ansStart, ansEnd);
		else
			printf("Route %d has no nice parts\n", r);
	}
}
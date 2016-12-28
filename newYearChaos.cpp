#include <bits/stdc++.h>
using namespace std;

int n, t, a[112345], ans;

int merge(int lo, int hi) {
	int i, j, k, result, temp[hi - lo + 1];
	i = lo;
	j = (lo + hi) / 2 + 1;
	k = result =  0;
	while (i <= (lo + hi) / 2 && j <= hi) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		} 
		else {
			// printf("lo : %d, hi : %d, i : %d, j : %d, subans : %d\n", lo, hi, i, j, (lo + hi) / 2 - i + 1);
			result += (lo + hi) / 2 - i + 1;
			temp[k++] = a[j++];
 		}
	}

	while (i <= (lo + hi) / 2) {
 			temp[k++] = a[i++];
 		}

 		while (j <= hi) {
 			temp[k++] = a[j++];
 		}

 		for (i = 0; i < hi - lo + 1; i++) {
 			a[i + lo] = temp[i];
 		}

 		return result;
}

int noOfInversions(int lo, int hi) {
	// printf("function called: %d %d\n", lo, hi);
	int result = 0;
	if (lo < hi) {
		result += noOfInversions(lo, (lo + hi) / 2);
		result += noOfInversions((lo + hi) / 2 + 1, hi);
		result += merge(lo, hi);
	}
	return result;
} 


int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		ans = 0;
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (max(a[i] - i, 0) > 2) {
				flag = false;
				break;
			}  
		}

		if (flag) {
			cout << noOfInversions(1, n) << endl;
			// for (int i = 1; i <= n; i++) {
			// 	cout << a[i] << " ";
			// }
			// cout << endl;
		}
		else {
			cout << "Too chaotic" << endl;
		}
	}
}
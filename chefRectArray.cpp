#include <bits/stdc++.h>
using namespace std;

int arr[1123][1123], maxRow[1123][1123], sum[1123][1123], n, m, a, b, q;

void preProcessMaxRow() {
	for (int i = 0; i < n; i++) {
		deque<int> d;
		int k = 0;
		for (; k < b; k++) {
			while (!d.empty() && arr[i][k] >= arr[i][d.back()]) {
				d.pop_back();
			}
			d.push_back(k);	
		}
		k--;
		maxRow[i][k] = arr[i][d.front()];

		for (int j = k + 1; j < m; j++) {
			if (!d.empty() && d.front() <= j - b) {
				d.pop_front();
			}
			while (!d.empty() && arr[i][j] >= arr[i][d.back()]) {
				d.pop_back();
			} 
			d.push_back(j);
			maxRow[i][j] = arr[i][d.front()];
		}
	}
}

void partialSum() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a, b, c, d;
			a = i > 0 && j > 0 ? sum[i - 1][j - 1] : 0;
			b = i > 0 ? sum[i - 1][j] : 0;
			c = j > 0 ? sum[i][j - 1] : 0;
			d = arr[i][j];

			sum[i][j] = b + c + d - a;
		}
	} 
}

int sumMatrix(int x, int y, int x1, int y1) {
	int a, b, c, d;
	a = x > 0 && y > 0 ? sum[x - 1][y - 1] : 0;
	b = x > 0 ? sum[x - 1][y1] : 0;
	c = y > 0 ? sum[x1][y - 1] : 0;
	d = sum[x1][y1];

	return d + a - b - c;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	partialSum();

	cin >> q;

	for (int t = 0; t < q; t++) {
		cin >> a >> b;
		int result;
		result = INT_MAX;
		preProcessMaxRow();


		for (int j = b - 1; j < m; j++) {
			deque<int> d;
			int k = 0;
			for (; k < a; k++) {
				while (!d.empty() && maxRow[k][j] >= maxRow[d.back()][j]) {
					d.pop_back();
				}
				d.push_back(k);	
			}
			k--;
			result = min(result, a * b * maxRow[d.front()][j] - sumMatrix(k - a + 1, j - b + 1, k, j));
			// printf("max = %d and sum = %d\n", a * b * maxRow[d.front()][j], sumMatrix(k - a + 1, j - b + 1, k, j));
			// printf("i = %d, j = %d, result = %d \n\n", k, j, result);

			for (int i = k + 1; i < n; i++) {
				if (!d.empty() && d.front() <= i - a) {
					d.pop_front();
				}
				while (!d.empty() && maxRow[i][j] >= maxRow[d.back()][j]) {
					d.pop_back();
				} 
				d.push_back(i);
				result = min(result, a * b * maxRow[d.front()][j] - sumMatrix(i - a + 1, j - b + 1, i, j));
				// printf("max = %d and sum = %d\n", a * b * maxRow[d.front()][j], sumMatrix(i - a + 1, j - b + 1, i, j));
				// printf("i = %d, j = %d, result = %d \n\n", i, j, result);
			}
		}

		cout << result << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;

int n, a[112345];
void merge(int *, int, int);
void mergeSort(int * a, int lo, int hi) {
	if (lo < hi) {
		mergeSort(a, lo, (lo + hi) / 2);
		mergeSort(a, (lo + hi) / 2 + 1, hi);
		merge(a, lo, hi);
	}
}

void merge(int * a, int lo, int hi) {
	int i, j, k, l, r, temp[hi - lo + 1];
	r = (lo + hi) / 2;
	l = r + 1;
	i = lo;
	j = l;
	k = 0;
	while (i <= r && j <= hi) {
		if (a[i] < a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}

	while (i <= r) {
		temp[k++] = a[i++];
	}

	while (j <= hi) {
		temp[k++] = a[j++];
	}

	for (i = lo; i <= hi; i++) {
		a[i] = temp[i - lo];
		//cout << a[i] << " ";
	}
	//cout << endl;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	mergeSort(a, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " "; 
	}	
	cout << endl;
}
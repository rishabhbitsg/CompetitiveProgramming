#include <bits/stdc++.h>
using namespace std;

int n1, n2, n3, h1, h2, h3;
stack<int> s1, s2, s3, s;

int main() {
	cin >> n1 >> n2 >> n3;
	for (int i = 0; i < n1; i++) {
		int h;
		cin >> h;
		s.push(h);
		h1 += h;
	}
	for (int i = 0; i < n1; i++) {
		s1.push(s.top());
		s.pop();
	}
	for (int i = 0; i < n2; i++) {
		int h;
		cin >> h;
		s.push(h);
		h2 += h;
	}
	for (int i = 0; i < n2; i++) {
		s2.push(s.top());
		s.pop();
	}
	for (int i = 0; i < n3; i++) {
		int h;
		cin >> h;
		s.push(h);
		h3 += h;
	}
	for (int i = 0; i < n3; i++) {
		s3.push(s.top());
		s.pop();
	}

	while (true) {
		if (h1 == h2 && h2 == h3) break;
		if (h1 > h2) {
			if (h1 > h3) {
				int h = s1.top();
				s1.pop();
				h1 -= h;
			}
			else {
				int h = s3.top();
				s3.pop();
				h3 -= h;
			}
		}
		else {
			if (h2 > h3) {
				int h = s2.top();
				s2.pop();
				h2 -= h;
			}
			else {
				int h = s3.top();
				s3.pop();
				h3 -= h;
			}
		}
	}

	cout << h1 << endl;
}
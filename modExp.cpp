#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
long long a, b;

long long exp(long long a, long long b) {
	if (b == 0) return 1;
	else if (b % 2 == 0) return ((exp(a, b / 2) % M) * (exp(a, b / 2) % M)) % M;
	else return ((exp(a, b / 2) % M) * ((exp(a, b / 2) * a) % M)) % M;
}

int main() {
	cin >> a >> b;
	cout << exp(a, b) << endl;
}
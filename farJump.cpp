#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 112345
#define M 1000000007

int n, friendliness[MAX], q;
long double logSum[MAX]; 
ll prod[MAX];
vector<int> d[MAX]; 

void initialize() {
	for (int i = 1; i < MAX; i++) {
		prod[i] = 1;
		for (int j = i; j < n; j += i) {
			d[j].push_back(i);
			prod[i] = 1LL * prod[i] * friendliness[j] % M;
			logSum[i] = logSum[i] + log10l((long double) friendliness[j]); 
		}
	}
}

int inv(int x) {
  return x == 1 ? 1 : 1LL * (M - M / x) * inv(M % x) % M;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> friendliness[i];
	}
 
	initialize();

	cin >> q;
	for (int i = 0; i < q; i++) {
		int qType, p, f, r;

		cin >> qType;
		if (qType == 1) {
			cin >> p >> f;
			if (p != 1) {
				int iv = inv(friendliness[p - 1]);
				for (auto x : d[p - 1]) {
					prod[x] = 1LL * prod[x] * iv % M * f % M;
					logSum[x] += log10l((long double) f) - log10l((long double) friendliness[p - 1]);
				}
			}
			friendliness[p - 1] = f;
		}
		else {
			cin >> r;
			int dig;
			long double fractPart, intPart;
			
			fractPart = modf(logSum[r] + log10l((long double) friendliness[0]), &intPart);
			// cout << "fractPart = " << fractPart << "log = " << logSum[r] << endl;
			dig = (int) pow(10, fractPart);
			cout << dig << " " << 1LL * prod[r] * friendliness[0] % M << endl;
			
		}
	}
}
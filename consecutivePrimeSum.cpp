#include<bits/stdc++.h>
using namespace std;

int isPrime[1000000];
vector<long long> v;
long long n;

bool isPrime2(long long a) {
	if (a % 2 == 0) {
		return false;
	}

	for (int i = 3; i * i <= a; i += 2) {
		if (a % i == 0) {
			return false;
		}
	}

	return true;
}

void sieve() {
	long long sum = 0;
	for (long long i = 2; i < 1000000; i++) {
		if (isPrime[i] == -1) {
			// if (i < 100) cout << i << endl;
			isPrime[i] = 1;
			sum += i;
			if (sum != 2) {
				v.push_back(sum);
				// cout << sum << endl;
			}
			for (long long j = i * i; j < 1000000; j += i) {
				// cout << j << endl;
				isPrime[j] = 0;
			} 
		}
	}
}

int main() {
	cin >> n;

	int ans = 0;
	long long sum = 2;

	for (int i = 0; i < 1000000; i++) {
		isPrime[i] = -1;
	}

	isPrime[0] = isPrime[1] = 0;
	// cout << 1 << endl;
	sieve();
	// cout << 2 << endl;
	// cout << v.size() << endl;
	for (auto x: v) {
		// cout << x << endl;
		if (x <= n && x < 1000000 && isPrime[x]) {
			ans++;
		}
		else if (x <= n && isPrime2(x)) {
			ans++;
		}
		else if (x > n) {
			break;
		}
	}

	cout << ans << endl;
}
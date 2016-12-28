#include <bits/stdc++.h>
using namespace std;

int n, m, region, point;	
vector< pair<int, string> > regions[11234];
string name;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> name >> region >> point;
		regions[region].push_back(make_pair(point, name));
	}

	for (int i = 1; i <= m; i++) {
		sort(regions[i].rbegin(), regions[i].rend());
		if (regions[i].size() > 2) {
			if (regions[i][1].first > regions[i][2].first) {
				cout << regions[i][0].second << " " << regions[i][1].second
					<< endl;
			}		
			else {
				cout << "?" << endl;
			}
		}
		else {
			cout << regions[i][0].second << " " << regions[i][1].second
				<< endl;
		}
	}
}
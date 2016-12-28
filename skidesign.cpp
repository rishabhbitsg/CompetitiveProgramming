/*
ID: rishabh36
PROG: skidesign
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int n, a[1123];

int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    
    fin >> n;
    for (int i = 0; i < n; i++) {
    	fin >> a[i];
    }
    fin.close();
    int ans = INT_MAX;
    sort(a, a + n);
    for (int minH = 1; minH <= 100; minH++) {
    	int currAns = 0;
    	for (int i = 0; i < n; i++) {
    		if (a[i] < minH) currAns += (minH - a[i]) * (minH - a[i]);
    		else if (a[i] > minH + 17) currAns += (a[i] - minH - 17) * (a[i] - minH - 17); 
    	}
    	ans = min(ans, currAns);
    }
    fout << ans << endl;
    fout.close();
}
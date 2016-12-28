#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
int t, n, m, a, b;

bool find(int *, int, int);
int root(int * a ,int i)
{
    while(a[i] != i)
    {
        a[i] = a[a[i]] ; 
		i = a[i]; 
    }
	return i;
}

void weighted_union(int * a,int * size, int u, int v)
{
    int root_u = root(a, u);
    int root_v = root(a, v);
    if (!find(a, u, v)) {
    	if(size[root_u] < size[root_v])
    	{
			a[root_u] = a[root_v];
			size[root_v] += size[root_u];
		}
    	else
    	{
			a[root_v] = a[root_u];
			size[root_u] += size[root_v];
		}
	}

}

void initialize(int * a, int * size, int n)
{
    for(int i = 1; i <= n; i++)
    {
		a[i] = i;
		size[i] = 1;
	}
}

 bool find( int * a, int u, int v)                           
{
	if(root(a, u) == root(a, v))
		return true;
	else
		return false;   
}
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int f[n + 1], size[n + 1];
		initialize(f, size, n);
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			weighted_union(f, size, a, b);
		}
		int total;
		long long cap;
		total = 0;
		cap = 1;
		for (int i = 1; i <= n; i++) {
		//	cout << f[i] << " ";
			if (i == root(f, i)) {
				total++;
				cap = (cap * size[i]) % M;
			}
		}
		//cout << endl;
		/*
		for (int i = 1; i <= n; i++) {
			cout << size[i] << " ";
		}
		cout << endl;*/

		cout << total << " " << cap << endl;
	}
}
#include <bits/stdc++.h>
using namespace std;

struct node {
	int time;
	int dur;
	int index; 

	node(int t, int d, int i) { time = t; dur = d; index = i;}
};

queue< node > q;
vector< node > v;
int n, b, t, d, next, current, result[212345];

int main() {
	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		cin >> t >> d;
		v.push_back(node(t, d, i));
	}

	q.push(v[0]);
	current = 0;
	next = 1;
	while (!q.empty()) {
		node tnode = q.front();
		q.pop();
		current = current < tnode.time ?
			tnode.time + tnode.dur : current + tnode.dur;
		result[tnode.index] = current;
		while (next < n && current > v[next].time) {
			if (q.size() < b) {
				//cout << "next = " << next << endl;
				q.push(v[next]);
			}
			else {
				result[next] = -1;
			}
			next++;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
	cout << endl;
}
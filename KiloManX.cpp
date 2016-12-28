#include <bits/stdc++.h>
using namespace std;

int best, currentShots, visited[32768];

struct node {
	int weapon;
	int shots;

	node(int w, int s) {weapon = w; shots = s;}
};

bool operator<(const node &node1, const node &node2) {
	if (node1.shots != node2.shots) return node1.shots > node2.shots;
	if (node1.weapon != node2.weapon) return node1.weapon < node2.weapon;
	return false;
}

class KiloManX {
public:
	int leastShots(vector<string> damageChart, vector<int> bossHealth) {
		priority_queue<node> q;
		q.push(node(0, 0));
		while (!q.empty()) {
			node n = q.top();
			q.pop();

			if (visited[n.weapon]) continue;
			visited[n.weapon] = 1;

			if (n.weapon == (1 << damageChart.size()) - 1) return n.shots;

			for (int i = 0; i < damageChart.size(); i++) {
				if (n.weapon >> i & 1) continue;

				int best = bossHealth[i];
				for (int j = 0; j < damageChart.size(); j++) {
					if (i == j) continue;
					if (!(n.weapon >> j & 1) || damageChart[j][i] == '0')
						continue;

					currentShots = bossHealth[i] / (damageChart[j][i] - '0');
					if (bossHealth[i] % (damageChart[j][i] - '0'))
						currentShots++;

					best = min(best, currentShots);
				}

				q.push(node(n.weapon | 1 << i, n.shots + best));
			}
		}
	}
};

/*
int main() {
	KiloManX k;
	string a1[] = {"1542", "7935", "1139", "8882"};
	vector<string> v1(a1, a1 + 4);
	int a2[] = {150, 150, 150, 150};
	vector<int> v2(a2, a2 + 4);
	cout << k.leastShots(v1, v2) << endl;
}
*/
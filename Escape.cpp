#include <bits/stdc++.h>
using namespace std;
int x1, x2, _y1, y2, graph[501][501], result, visited[501][501]; 
queue< pair<int, int> > current, frontier;
pair<int, int> tpair, tpair2;

class Escape {
public:
	int lowest(vector<string> harmful, vector<string> deadly) {
		for (auto x: harmful) {
			istringstream ss1(x);
			ss1 >> x1 >> _y1 >> x2 >> y2;
			for (int i = min(x1, x2); i <= max(x1, x2); i++) {
				for (int j = min(_y1, y2); j <= max(_y1, y2); j++) {
					// cout << "harmful node" << endl;
					graph[i][j] = 1;
				}
			}
		}


		for (auto x: deadly) {
			istringstream ss1(x);
			ss1 >> x1 >> _y1 >> x2 >> y2;
			for (int i = min(x1, x2); i <= max(x1, x2); i++) {
				for (int j = min(_y1, y2); j <= max(_y1, y2); j++) {
					// cout << "deadly node" << endl;
					graph[i][j] = -1;
				}
			}
		}

		tpair.first = 0;
		tpair.second = 0;
		visited[0][0] = 1;
		current.push(tpair); 
		while (!current.empty() || !frontier.empty()) {
			while (!current.empty()) {
				tpair = current.front();
				current.pop();

				x1 = tpair.first;
				_y1 = tpair.second;

				if (x1 == 500 && _y1 == 500) {
					return result;
				}
				addToQ(x1, _y1 + 1);
				addToQ(x1, _y1 - 1);
				addToQ(x1 + 1, _y1);
				addToQ(x1 - 1, _y1);
				// cout << "result = " << result << endl;
			}
			//cout << "result = " << result << endl;
			result++;
			swap(current, frontier);
		}

		return -1;
	}

private:
	void addToQ(int x, int y) {
		if (x < 0 || x > 500) return;
		if (y < 0 || y > 500) return;

		if (visited[x][y] == 0) {
			tpair2.first = x;
			tpair2.second = y;
			visited[x][y] = 1;
			if (graph[x][y] == 0) {
				//cout << "Normal node" << endl;
				current.push(tpair2);
			}
			else if (graph[x][y] == 1) {
				frontier.push(tpair2);
			}
		}
	}
};

/*
int main() {
	Escape e;
	string a1[] = {"500 0 0 500"};
	string a2[] = {"0 0 0 0"};
	vector<string> v1(a1, a1 + 1);
	vector<string> v2(a2, a2 + 1);
	cout << e.lowest(v1, v2) << endl;
}
*/
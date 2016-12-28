/*
ID: rishabh36
PROG: wormhole
LANG: C++11            
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 12
int N, X[MAX_N + 1], Y[MAX_N + 1], partner[MAX_N + 1], nextToRight[MAX_N + 1];

bool cycle_exists() {
  for (int i = 1; i <= N; i++) {
    int hole = i;
    for (int j = 0; j < N; j++) {
      hole = nextToRight[partner[hole]];
    } 
    if (hole != 0) return true;
  }
  return false;
}

int solve() {
  int total = 0;
  // pair the first two unpaired wormhole
  int i;
  for (i = 1; i <= N; i++) {
    if (partner[i] == 0) break;
  }

  if (i > N) {
    if (cycle_exists()) return 1;
    return 0;
  }
  
  for (int j = i + 1; j <= N; j++) {
    if (partner[j] == 0) {
      partner[j] = i;
      partner[i] = j;
      total += solve();
      partner[i] = partner[j] = 0;
    }
  }
  return total;
}

  
int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");

    fin >> N;
    for (int i = 1; i <= N; i++) {
      fin >> X[i] >> Y[i];
    }
    fin.close();
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (i != j) {
          if (Y[i] == Y[j] && X[j] > X[i]) {
            if (nextToRight[i] == 0) nextToRight[i] = j;
            else if (X[j] < X[nextToRight[i]]) nextToRight[i] = j;
          }
        }
      }
    }
    fout << solve() << endl;
    fout.close();
    return 0;
}

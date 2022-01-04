#include <bits/stdc++.h>

using namespace std;

int length(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v(k, {0, 0});
  for (pair<int, int> &p: v)
    cin >> p.first >> p.second;
  int ans;
  int l;
  for (int i(0); i < n; ++i) {
    for (int j(0); j < n; ++j) {
      if (i == j)
        continue;
      for (int y(0); y < k; ++y) {

      }
    }
  }
  return 0;
}

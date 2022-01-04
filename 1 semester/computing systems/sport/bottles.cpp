//
// Created by yeloki on 01.01.2022.
//

#include <bits/stdc++.h>

using namespace std;

int is(int v, int m, int p) {
  return ((v % m) != 0) * p;
}

int main() {
  int n, k, m, p;
  uint64_t result = 0;
  cin >> n >> k >> m >> p;
  /// \vars n - bottles count
  /// \vars k - container switch
  /// \vars m - manipulator maximum bottles
  /// \vars p - manipulator spending time
  vector<pair<int, int>> conv;
  vector<pair<int, int>> dp(n + 1, {0, 0});
  for (int i(0); i < n; ++i) {
    int a;
    cin >> a;
    if (conv.empty() || (*conv.rbegin()).first != a)
      conv.emplace_back(a, 1);
    else
      ++(*conv.rbegin()).second;
  }
  result += conv[0].second;
  dp[0] = {conv[0].first, conv[0].second};
  for (int i(1); i < n + 1; ++i) {

  }
  cout << (*dp.rbegin()).second << endl;
}

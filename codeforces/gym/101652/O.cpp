/*
 *  WATCH THIS
 */
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll N = 1e5 * 3 + 2, oo = INT_MAX, mod = 1e9 + 7;

void debug() { cerr << endl; }

template<typename Head, typename... Tail>
void debug(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug(T...);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<char>> v(n + 1, vector<char>(n + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> v[i][j];
    }
  }
  bool ok = false;
  for (int i = 0; i < n; ++i) {
    vector<int> cntrow(91, 0);
    for (int j = 0; j < n; ++j) {
      if (cntrow[v[i][j]] > 0) {
        ok = true;
        break;
      }
      cntrow[v[i][j]]++;
    }
    if (ok)break;
  }
  for (int i = 0; i < n; ++i) {
    vector<int> cntcol(91, 0);
    for (int j = 0; j < n; ++j) {
      if (cntcol[v[j][i]] > 0) {
        ok = true;
        break;
      }
      cntcol[v[j][i]]++;
    }
    if (ok)break;
  }
  if (ok) {
    return cout << "No\n", 0;
  }
  vector<int> row;
  ok = false;
  for (int i = 0; i < n - 1; ++i) {
    if (v[0][i] > v[0][i + 1]) {
      ok = true;
      break;
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    if (v[i][0] > v[i + 1][0]) {
      ok = true;
      break;
    }
  }
  if (ok) {
    return cout << "Not Reduced\n", 0;
  }
  cout << "Reduced\n";
  return 0;
}
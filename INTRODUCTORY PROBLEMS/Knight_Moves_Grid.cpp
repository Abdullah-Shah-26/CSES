#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vpii = vector<pii>;
using vvpii = vector<vector<pii>>;
using vpll = vector<pll>;
using vvpll = vector<vector<pll>>;

const int INF = 1e9;
const ll LINF = 4e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

int row[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
int col[8] = {-1, 1, -2, 2, -1, 1, 2, -2};

int main() {
  int n;
  cin >> n;

  vvi dist(n, vi(n, INF));
  queue<pii> q;

  q.push({0, 0});
  dist[0][0] = 0;

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    for (int k = 0; k < 8; k++) {
      int nr = r + row[k];
      int nc = c + col[k];

      if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == INF) {
        dist[nr][nc] = dist[r][c] + 1;
        q.push({nr, nc});
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << dist[i][j] << " ";
    cout << endl;
  }

  return 0;
}
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
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

int main() {

  int n, q;
  cin >> n >> q;

  vvi mat(n, vi(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char ch;
      cin >> ch;

      if (ch == '*')
        mat[i][j] = 1;
    }
  }

  vvi pref(n + 1, vi(n + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + mat[i - 1][j - 1];
    }
  }

  while (q--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int ans = pref[r2][c2] - pref[r1 - 1][c2] - pref[r2][c1 - 1] + pref[r1 - 1][c1 - 1];

    cout << ans << endl;
  }

  return 0;
}
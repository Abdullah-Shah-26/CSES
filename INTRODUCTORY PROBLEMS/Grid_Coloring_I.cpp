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
using T = tuple<ll, ll, ll>;

const int INF = 1e9;
const ll LINF = 4e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

void solve() {
  int n, m;
  cin >> n >> m;

  vs grid(n);

  for (auto &row : grid)
    cin >> row;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      set<char> st;

      if (i != 0)
        st.insert(grid[i - 1][j]);

      if (j != 0)
        st.insert(grid[i][j - 1]);

      // Original letter is banned too since each cell must change its color
      st.insert(grid[i][j]);

      for (char ch = 'A'; ch <= 'D'; ch++) {
        if (!st.count(ch)) {
          grid[i][j] = ch;
          break;
        }
      }
    }
  }

  for (auto &row : grid)
    cout << row << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}
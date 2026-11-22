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

  int n, k;
  cin >> n >> k;

  vi p(k);
  for (auto &x : p)
    cin >> x;

  // dp[i] = true // Winning position
  // dp[i] = false // Losing position
  vb dp(n + 1);

  dp[0] = false; // No stick for P1, he lost

  // If i can make opponent land a losing state, then i is winning

  for (int i = 1; i <= n; i++) {
    dp[i] = false;

    for (int move : p) {
      if (move > i)
        continue;

      if (dp[i - move] == false) {
        dp[i] = true;
        break;
      }
    }
  }

  for (int i = 1; i <= n; i++)
    cout << (dp[i] ? 'W' : 'L');

  return 0;
}
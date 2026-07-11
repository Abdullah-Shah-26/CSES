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

// Can be solved using de-rangements or PIE

int main() {

  ll n;
  cin >> n;

  if (n == 1) {
    cout << 0;
    return 0;
  }

  vll dp(n + 1, 0);
  dp[1] = 0;
  dp[2] = 1;

  for (int i = 3; i <= n; i++)
    dp[i] = (i - 1) * ((dp[i - 1] + dp[i - 2]) % MOD) % MOD;

  cout << dp[n] << endl;

  return 0;
}
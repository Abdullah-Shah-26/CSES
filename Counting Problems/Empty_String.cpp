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

const int N = 505;

ll fact[N], invFact[N];
ll dp[N][N];

ll modPow(ll a, ll b) {
  ll res = 1;

  while (b) {
    if (b & 1)
      res = res * a % MOD;

    a = a * a % MOD;
    b >>= 1;
  }

  return res;
}

ll nCr(int n, int r) {
  if (r < 0 || r > n)
    return 0;

  return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void precompute() {
  fact[0] = 1;

  for (ll i = 1; i < N; i++)
    fact[i] = fact[i - 1] * i % MOD;

  invFact[N - 1] = modPow(fact[N - 1], MOD - 2);

  for (ll i = N - 2; i >= 0; i--)
    invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

ll f(int l, int r, string &s) {

  // Empty string
  if (l > r)
    return 1;

  // Odd len string -> Cannot empty
  // Since every operations removes 2 chars
  if ((r - l + 1) & 1)
    return 0;

  if (dp[l][r] != -1)
    return dp[l][r];

  ll ans = 0;

  for (int k = l + 1; k <= r; k += 2) {
    if (s[l] != s[k])
      continue;

    // Inside removal operations
    int p = (k - l - 1) / 2;

    // Outside removal operations
    int q = (r - k) / 2;

    ll ways = f(l + 1, k - 1, s);
    ways = ways * f(k + 1, r, s) % MOD;
    ways = ways * nCr(p + q + 1, p + 1) % MOD;

    ans = (ans + ways) % MOD;
  }

  return dp[l][r] = ans;
}

void solve() {
  string s;
  cin >> s;

  int n = s.size();

  memset(dp, -1, sizeof(dp));

  cout << f(0, n - 1, s) << endl;
}

int main() {
  precompute();

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}
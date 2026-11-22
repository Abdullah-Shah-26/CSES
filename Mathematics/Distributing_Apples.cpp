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

vll fact, invFact;

ll nCr(ll n, ll r) {
  if (r < 0 || r > n)
    return 0;

  return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

ll binExpo(ll a, ll b) {
  ll ans = 1;

  while (b) {
    if (b & 1)
      ans = ans * a % MOD;

    a = a * a % MOD;
    b >>= 1;
  }

  return ans;
}

// Stars & Bars 

int main() {

  ll N, M; // N, no of children, M, no of apples 
  cin >> N >> M;

  ll n = N + M;

  fact.assign(n + 1, 0);
  invFact.assign(n + 1, 0);

  fact[0] = 1;
  for (ll i = 1; i <= n; i++)
    fact[i] = fact[i - 1] * i % MOD;

  invFact[n] = binExpo(fact[n], MOD - 2);
  for (ll i = n - 1; i >= 0; i--)
    invFact[i] = invFact[i + 1] * (i + 1) % MOD;

  cout << nCr(M + (N-1), M) << endl;

  return 0;
}
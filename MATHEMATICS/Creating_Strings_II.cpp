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

/*

s = aabbbc
n = 6
a = 2!
b = 3!
c = 1!

ans = 6!/(2!3!) 

*/

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

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

int main() {

  string s;
  cin >> s;

  ll N = s.size();

  vll fact(N + 1, 0);
  fact[0] = 1;

  for (ll i = 1; i <= N; i++)
    fact[i] = fact[i - 1] * i % MOD;

  vll invFact(N + 1, 0);
  invFact[N] = binExpo(fact[N], MOD - 2);

  for (ll i = N - 1; i >= 0; i--)
    invFact[i] = invFact[i + 1] * (i + 1) % MOD;

  vll freq(26, 0);
  for (char &ch : s)
    freq[ch - 'a']++;

  ll ans = fact[N];
  for (auto &f : freq)
    ans = (ans * invFact[f]) % MOD;

  cout << ans << endl;

  return 0;
}
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

ll binExpo(ll a, ll b, ll mod) {
  ll ans = 1;

  a %= mod;

  while (b) {
    if (b & 1)
      ans = ans * a % mod;

    a = a * a % mod;
    b >>= 1;
  }

  return ans;
}

int main() {

  int n;
  cin >> n;

  while (n--) {
    ll a, b, c;
    cin >> a >> b >> c;

    ll exp = binExpo(b, c, MOD - 1);
    ll ans = binExpo(a, exp, MOD);
    
    cout << ans << endl;
  }

  return 0;
}
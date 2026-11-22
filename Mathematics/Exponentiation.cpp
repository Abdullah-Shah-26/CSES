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

  int n;
  cin >> n;

  while (n--) {
    ll a, b;
    cin >> a >> b;
    cout << binExpo(a, b) << endl;
  }

  return 0;
}
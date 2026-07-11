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
const int INV2 = 500000004; // inverse of 2 % MOD

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// TC = O(sqrt(N))

int main() {

  ll n;
  cin >> n;

  ll d = 1;
  ll ans = 0;

  // [d....r]

  while (d <= n) {

    ll q = n / d;

    // Largest r value such that floor(n/x) == q for every x in [d,r]
    ll r = n / q;

    // No of elem in current block [d,r]
    ll cnt = (r - d + 1);

    // We need :
    // d + (d + 1) + .... + r
    //
    // Arithmetic Progression :
    // (d + r) * (r - d + 1)/2

    ll firstLast = (d + r);

    // To avoid modular inverse (division by 2)
    // Divide which ever factor is even
    // One of them is guarenteed to e even
    if (cnt % 2 == 0)
      cnt /= 2;
    else
      firstLast /= 2;

    // Sum of all elem from [d..r] % MOD
    ll sum = (cnt % MOD) * (firstLast % MOD) % MOD;

    // Contribution of entire block
    // q * (d + (d + 1) + ..... + r)
    ans = (ans + (q % MOD) * sum) % MOD;

    // Continue from next block
    d = r + 1;
  }

  cout << ans;

  return 0;
}
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

int n;
int a[21];
ll ans = LLONG_MAX;

void f(int i, ll x, ll y) {
  if (i == n) {
    ans = min(ans, abs(x - y));
    return;
  }

  f(i + 1, x + a[i], y);
  f(i + 1, x, y + a[i]);
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  f(0, 0, 0);

  cout << ans << endl;

  return 0;
}
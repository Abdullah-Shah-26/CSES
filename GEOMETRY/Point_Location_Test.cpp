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
const ll LINF = 4e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

void solve() {

  ll x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  // slope of P1-P2 = s12
  // slope of P2-P3 = s23

  // if(s12 > s23) P3 lies on right
  // if(s12 < s23) P3 lies on left

  ll val = (x3 - x2) * (y2 - y1) - (x2 - x1) * (y3 - y2);

  if (val < 0)
    cout << "LEFT" << endl;
  else if (val > 0)
    cout << "RIGHT" << endl;
  else
    cout << "TOUCH" << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
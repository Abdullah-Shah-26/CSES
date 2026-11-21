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

struct P {
  ll x, y;
};

// Orientation of 3 points A, B, C
// Imagine moving from A -> B, then towards C.
//
// Cross product:
// > 0 : Left turn
// < 0 : Right turn
// = 0 : Collinear (same straight line)
int ori(P a, P b, P c) {

  ll val = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);

  // Left
  if (val > 0)
    return 1;

  // Right
  if (val < 0)
    return 2;

  // Collinear
  return 0;
}

// Point C lies on segment AB:
bool onSeg(P a, P b, P c) {
  return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y &&
         c.y <= max(a.y, b.y);
}

void solve() {
  P a, b, c, d;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

  ll o1 = ori(a, b, c);
  ll o2 = ori(a, b, d);
  ll o3 = ori(c, d, a);
  ll o4 = ori(c, d, b);

  if (o1 != o2 && o3 != o4)
    YES;
  else if (o1 == 0 && onSeg(a, b, c))
    YES;
  else if (o2 == 0 && onSeg(a, b, d))
    YES;
  else if (o3 == 0 && onSeg(c, d, a))
    YES;
  else if (o4 == 0 && onSeg(c, d, b))
    YES;
  else
    NO;
}

int main() {

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
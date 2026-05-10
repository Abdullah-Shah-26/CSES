#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// order_of_key(k) : No of Elements < k
// *find_by_order(i) : Value at idx i (0 - based)

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvpi = vector<vector<pi>>;

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
static const auto fastio = []()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// ---------- Macros ----------
#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
#define pv(a)                 \
  do                          \
  {                           \
    for (const auto &x : (a)) \
      cout << x << ' ';       \
    cout << '\n';             \
  } while (0)
#define rm(mat)         \
  for (auto &r : (mat)) \
    for (auto &x : (r)) \
  cin >> x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define nl        \
  do              \
  {               \
    cout << '\n'; \
  } while (0)

class Fenwick
{
public:
  vi bit;
  int n;

  Fenwick(int size)
  {
    n = size;
    bit.resize(n + 1);
  }

  void update(int idx, int val)
  {
    while (idx <= n)
    {
      bit[idx] += val;
      idx += (idx & -idx);
    }
  }

  int query(int idx)
  {
    int sum = 0;
    while (idx > 0)
    {
      sum += bit[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }
};

// ---------- Solve ---------
void solve()
{
  int n;
  cin >> n;

  vector<vector<int>> a;
  vi rights;

  for (int i = 0; i < n; i++)
  {
    int l, r;
    cin >> l >> r;
    a.push_back({l, r, i});

    rights.pb(r);
  }

  auto cmp = [&](auto &a, auto &b)
  {
    if (a[0] == b[0])
    {
      return a[1] > b[1];
    }

    return a[0] < b[0];
  };

  // Left Increasing
  // Right Decreasing

  sort(all(a), cmp);
  sort(all(rights));

  // Fenwick Tree + Co-ordinate Compression
  rights.erase(unique(rights.begin(), rights.end()), rights.end());
  int m = rights.size();

  Fenwick ft(m); // Count of compressed right end points

  vi contains(n);
  vi contained(n);

  for (int i = 0; i < n; i++)
  {
    int r = a[i][1];
    int idx = a[i][2];

    // Getting Compressed Position
    int pos = lower_bound(all(rights), r) - rights.begin() + 1;

    int smaller = ft.query(pos - 1);

    contained[idx] = i - smaller;

    ft.update(pos, 1);
  }

  Fenwick ft2(m);

  for (int i = n - 1; i >= 0; i--)
  {
    int r = a[i][1];
    int idx = a[i][2];

    int pos = lower_bound(all(rights), r) - rights.begin() + 1;

    contains[idx] = ft2.query(pos);

    ft2.update(pos, 1);
  }

  pv(contains);
  pv(contained);
}

// ---------- Main ----------
int main()
{
  solve();
  return 0;
}
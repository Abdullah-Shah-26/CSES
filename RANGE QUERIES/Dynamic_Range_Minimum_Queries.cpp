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

class SegTree {
private:
  int n;
  vll seg;

  void build(int i, int l, int r, vll &a) {
    if (l == r) {
      seg[i] = a[l];
      return;
    }

    int mid = (l + r) >> 1;
    build(2 * i, l, mid, a);
    build(2 * i + 1, mid + 1, r, a);

    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
  }

  // Point update
  void update(int i, int l, int r, int idx, ll val) {
    if (l == r) {
      seg[i] = val;
      return;
    }

    int mid = (l + r) >> 1;

    if (idx <= mid)
      update(2 * i, l, mid, idx, val);
    else
      update(2 * i + 1, mid + 1, r, idx, val);

    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
  }

  // Range min query
  ll query(int i, int l, int r, int ql, int qr) {
    if (l > qr || r < ql)
      return LINF;

    if (l >= ql && r <= qr)
      return seg[i];

    int mid = (l + r) >> 1;

    return min(query(2 * i, l, mid, ql, qr),
               query(2 * i + 1, mid + 1, r, ql, qr));
  }

public:
  SegTree(vll &a) {
    n = a.size();

    seg.assign(4 * n, LINF);

    build(1, 0, n - 1, a);
  }

  void update(int idx, ll val) { update(1, 0, n - 1, idx, val); }

  ll query(int l, int r) {
    if (l > r)
      return LINF;

    return query(1, 0, n - 1, l, r);
  }
};

int main() {

  ll n, q;
  cin >> n >> q;

  vll a(n);
  for (auto &x : a)
    cin >> x;

  SegTree seg(a);

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int idx;
      ll val;

      cin >> idx >> val;

      idx--;
      a[idx] = val;
      seg.update(idx, val);
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;

      cout << seg.query(l, r) << endl;
    }
  }

  return 0;
}
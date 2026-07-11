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
  vector<ll> seg;

  void build(int node, int l, int r, vector<ll> &a) {

    if (l == r) {
      seg[node] = a[l];
      return;
    }

    int mid = (l + r) / 2;

    build(2 * node, l, mid, a);
    build(2 * node + 1, mid + 1, r, a);

    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
  }

  void update(int node, int l, int r, int idx, ll val) {

    if (l == r) {
      seg[node] = val;
      return;
    }

    int mid = (l + r) / 2;

    if (idx <= mid)
      update(2 * node, l, mid, idx, val);
    else
      update(2 * node + 1, mid + 1, r, idx, val);

    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
  }

  int findFirst(int i, int l, int r, ll rooms) {

    if (l == r)
      return l;

    int mid = (l + r) >> 1;

    // Always try left child first
    if (seg[2 * i] >= rooms)
      return findFirst(2 * i, l, mid, rooms);

    return findFirst(2 * i + 1, mid + 1, r, rooms);
  }

public:
  SegTree(vll &a) {
    n = a.size();

    seg.assign(4 * n, 0);

    build(1, 0, n - 1, a);
  }

  // -1 if no hotel can accomodate the group
  int allocate(ll rooms, vll &a){
    if(seg[1] < rooms) // root -> max free rooms among all hotels
      return -1;

    int idx = findFirst(1, 0, n-1, rooms);

    a[idx] -= rooms;

    update(1, 0, n-1, idx, a[idx]);

    return idx;
  }
};

int main() {

  ll n, m;
  cin >> n >> m;

  vll hotels(n);
  for (auto &x : hotels) {
    cin >> x;
  }

  SegTree seg(hotels);

  for (int i = 0; i < m; i++) {
    ll rooms;
    cin >> rooms;

    int hotel = seg.allocate(rooms, hotels);

    if (hotel == -1) {
      cout << 0 << " ";
    } else {
      cout << hotel + 1 << " ";
    }
  }

  return 0;
}
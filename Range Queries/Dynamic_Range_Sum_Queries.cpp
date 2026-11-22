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

class Fenwick {
private:
  int n;
  vector<ll> bit;

public:
  Fenwick(int n) {
    this->n = n;
    bit.assign(n + 1, 0);
  }

  void update(int idx, ll val) {
    idx++;

    while (idx <= n) {
      bit[idx] += val;
      idx += idx & -idx;
    }
  }

  ll query(int idx) {
    idx++;

    ll sum = 0;

    while (idx > 0) {
      sum += bit[idx];
      idx -= idx & -idx;
    }

    return sum;
  }

  ll rangeQuery(int left, int right) {
    if (left > right)
      return 0;

    return query(right) - (left ? query(left - 1) : 0);
  }
};

int main() {

  ll n, q;
  cin >> n >> q;

  vll a(n);
  Fenwick ft(n + 1);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ft.update(i, a[i]);
  }

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) { // Point update
      int pos;
      ll val;
      cin >> pos >> val;
      pos--;

      ll delta = val - a[pos];
      a[pos] = val;

      ft.update(pos, delta);

    } else { // Range query
      int l, r;
      cin >> l >> r;
      l--, r--;
      cout << ft.rangeQuery(l, r) << endl;
    }
  }

  return 0;
}
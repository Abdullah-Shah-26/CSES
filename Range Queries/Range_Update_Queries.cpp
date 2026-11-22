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
  for (ll &x : a) {
    cin >> x;
  }

  Fenwick ft(n + 2);

  ft.update(0, a[0]);

  // Ft is used as diff array
  for (int i = 1; i < n; i++)
    ft.update(i, a[i] - a[i - 1]);

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int l, r;
      ll u;

      cin >> l >> r >> u;
      l--, r--;

      ft.update(l, +u);
      ft.update(r + 1, -u);

    } 
    else {
      int idx;
      cin >> idx;

      idx--;

      cout << ft.query(idx) << endl;
    }
  }

  return 0;
}
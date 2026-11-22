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

int main() {

  int n, q;
  cin >> n >> q;

  vi a(n);
  for (int &x : a)
    cin >> x;

  // Important optimization : Co-ordinate compression
  vi vals = a;
  
  sort(begin(vals), end(vals));
  vals.erase(unique(begin(vals), end(vals)), end(vals));

  for (int i = 0; i < n; i++) {
    int rank = lower_bound(begin(vals), end(vals), a[i]) - vals.begin();

    a[i] = rank;
  }

  vector<array<int, 3>> queries(q);

  for (int i = 0; i < q; i++) {
    cin >> queries[i][0] >> queries[i][1];
    queries[i][0]--;
    queries[i][1]--;
    queries[i][2] = i;
  }

  int B = max(1, (int)sqrt(n));

  sort(begin(queries), end(queries), [&](auto &a, auto &b) {
    auto [aL, aR, i1] = a;
    auto [bL, bR, i2] = b;

    int x = aL / B;
    int y = bL / B;

    if (x != y)
      return x < y;

    if (x & 1)
      return aR > bR;

    return aR < bR;
  });

  int distinct = 0;
  int L = 0, R = -1;

  vi ans(q);
  vi freq(n + 1, 0);

  auto add = [&](int x) {
    freq[x]++;

    if (freq[x] == 1)
      distinct++;
  };

  auto remove = [&](int x) {
    freq[x]--;

    if (freq[x] == 0)
      distinct--;
  };

  for (auto [l, r, i] : queries) {

    // Expand
    while (L > l) {
      L--;
      add(a[L]);
    }

    while (R < r) {
      R++;
      add(a[R]);
    }

    // Shrink
    while (L < l) {
      remove(a[L]);
      L++;
    }

    while (R > r) {
      remove(a[R]);
      R--;
    }

    ans[i] = distinct;
  }

  for (auto x : ans)
    cout << x << '\n';

  return 0;
}
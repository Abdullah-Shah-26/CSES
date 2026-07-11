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

class SparseTable {
private:
  int n;
  int LOG;

  // st[i][j] = min in range [i, i + 2^j - 1]
  vvll st;

public:
  SparseTable(vll &a) {
    n = a.size();

    // Max power of 2 needed
    LOG = log2(n) + 1;

    st.assign(n, vll(LOG));

    // Base case :
    // Intervals of len = 1
    for (int i = 0; i < n; i++)
      st[i][0] = a[i];

    // j = power of 2
    for (int j = 1; j < LOG; j++) {

      // Start idx of interval
      for (int i = 0; i + (1 << j) <= n; i++) {

        ll left = st[i][j - 1];
        ll right = st[i + (1 << (j - 1))][j - 1];
        st[i][j] = min(left, right);
      }
    }
  }

  // Min in [l,r]
  ll query(int l, int r) {
    int len = r - l + 1;

    // Largest pow of 2 <= len
    int k = log2(len);

    return min(st[l][k], st[r - (1 << k) + 1][k]);
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  SparseTable sp(a);

  while (q--) {
    int l, r;
    cin >> l >> r;

    l--, r--;

    cout << sp.query(l, r) << endl;
  }
}
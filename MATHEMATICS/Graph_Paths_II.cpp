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

vvll multiply(const vvll &A, const vvll &B) {
  int n = A.size();

  vvll C(n, vll(n, LINF));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int x = 0; x < n; x++) {

        if (A[i][x] == LINF || B[x][j] == LINF)
          continue;

        C[i][j] = min(C[i][j], A[i][x] + B[x][j]);
      }
    }
  }

  return C;
}

vvll matExpo(vvll base, ll exp) {
  int n = base.size();

  vvll ans(n, vll(n, LINF));

  for (int i = 0; i < n; i++)
    ans[i][i] = 0;

  while (exp) {
    if (exp & 1)
      ans = multiply(ans, base);

    base = multiply(base, base);
    exp >>= 1;
  }

  return ans;
}

int main() {
  int n, m;
  ll k;

  cin >> n >> m >> k;

  vvll base(n, vll(n, LINF));

  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;

    cin >> u >> v >> w;

    --u;
    --v;

    base[u][v] = min(base[u][v], w);
  }

  vvll res = matExpo(base, k);

  if (res[0][n - 1] == LINF)
    cout << -1 << '\n';
  else
    cout << res[0][n - 1] << '\n';

  return 0;
}
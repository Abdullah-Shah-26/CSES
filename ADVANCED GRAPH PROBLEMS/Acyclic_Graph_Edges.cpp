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

void solve() {
  int n, m;
  cin >> n >> m;

  vvi adj(n);
  vpii edges;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].pb(v);
    adj[v].pb(u);
    edges.pb({u, v});
  }

  vi order;
  vb vis(n, false);

  function<void(int)> dfs = [&](int u) {
    vis[u] = true;
    order.pb(u);

    for (int v : adj[u])
      if (!vis[v])
        dfs(v);
  };

  for (int u = 0; u < n; u++)
    if (!vis[u])
      dfs(u);

  vi tin(n, 0);

  for (int i = 0; i < (int)order.size(); i++)
    tin[order[i]] = i;

  for (auto &[u, v] : edges) {
    if (tin[u] < tin[v])
      cout << u + 1 << " " << v + 1 << endl;
    else
      cout << v + 1 << " " << u + 1 << endl;
  }
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}
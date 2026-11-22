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

struct DSU {
  int n;
  vi parent, sz;

  DSU(int n) {
    this->n = n;
    parent.assign(n, 0);
    sz.assign(n, 1);
    iota(all(parent), 0);
  }

  int find(int x) {
    if (x == parent[x])
      return x;

    return parent[x] = find(parent[x]);
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
      return false;

    if (sz[u] < sz[v])
      swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];

    return true;
  }
};

struct Edge {
  int u, v, id;
  ll w;
};

const int LOG = 20;

void solve() {
  int n, m;
  cin >> n >> m;

  DSU dsu(n);
  vvpll adj(n);
  vector<Edge> edges;

  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--;
    v--;
    edges.pb({u, v, i, w});
  }

  sort(all(edges), [&](auto &a, auto &b) { return a.w < b.w; });

  ll mst = 0;
  for (auto [u, v, i, w] : edges) {
    if (dsu.unite(u, v)) {
      mst += w;
      adj[u].pb({v, w});
      adj[v].pb({u, w});
    }
  }

  vvi up(n, vi(LOG));
  vvll mx(n, vll(LOG));
  vll depth(n, 0);

  function<void(int, int)> dfs = [&](int u, int p) {
    up[u][0] = p;

    for (auto [v, w] : adj[u]) {
      if (v == p)
        continue;

      mx[v][0] = w;
      depth[v] = depth[u] + 1;

      dfs(v, u);
    }
  };

  dfs(0, 0);

  for (int j = 1; j < LOG; j++) {
    for (int u = 0; u < n; u++) {
      up[u][j] = up[up[u][j - 1]][j - 1];
      mx[u][j] = max(mx[u][j - 1], mx[up[u][j - 1]][j - 1]);
    }
  }

  function<ll(int, int)> maxEdge = [&](int u, int v) {
    ll ans = 0;

    if (depth[u] < depth[v])
      swap(u, v);

    int diff = depth[u] - depth[v];

    for (int j = LOG - 1; j >= 0; j--) {
      if (diff & (1 << j)) {
        ans = max(ans, mx[u][j]);
        u = up[u][j];
      }
    }

    if (u == v)
      return ans;

    for (int j = LOG - 1; j >= 0; j--) {
      if (up[u][j] != up[v][j]) {
        ans = max({ans, mx[u][j], mx[v][j]});
        u = up[u][j];
        v = up[v][j];
      }
    }

    ans = max({ans, mx[u][0], mx[v][0]});

    return ans;
  };

  vb ans(m);
  for (auto [u, v, i, w] : edges) {
    ll newCost = mst + w - maxEdge(u, v);

    if (newCost == mst) {
      ans[i] = true;
    }
  }

  for (auto x : ans) {
    if (x)
      YES;
    else
      NO;
  }
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}
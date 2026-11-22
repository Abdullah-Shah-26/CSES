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

Task :
Choose a direction for each edge so that the resulting directed graph is
strongly connected.

==========================
*/

void solve() {
  int n, m;
  cin >> n >> m;

  vvi adj(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  bool bridge = false;

  vpii ans;
  vi low(n, 0);
  vi tin(n, 0);
  int timer = 0;

  function<void(int, int)> dfs = [&](int u, int p) {
    tin[u] = low[u] = ++timer;

    for (int v : adj[u]) {
      if (v == p)
        continue;

      // Not visited
      // Tree edge : u --> v
      if (!tin[v]) {
        ans.pb({u, v});

        dfs(v, u);

        low[u] = min(low[u], low[v]);

        if (low[v] > tin[u])
          bridge = true;
      }
      
      // Already visited
      // Back edge : 
      else {
        if (tin[v] < tin[u]) {
          ans.pb({u, v});
          low[u] = min(low[u], tin[v]);
        }
      }
    }
  };

  int comp = 0;
  for (int u = 0; u < n; u++) {
    if (tin[u] == 0) {
      comp++;
      dfs(u, -1);
    }
  }

  // If the graph isn't connected then a SCC orientation is not possible
  if (comp > 1 || bridge) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  for (auto [u, v] : ans)
    cout << ++u << " " << ++v << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}
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

Length of the shortest cycle (Girth)

    s
   / \
  a   b
  |   |
  u---v

d[u] = 2
d[v] = 2
cycleLen = d[u] + d[v] + 1 = 5
  
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

  int ans = INF;

  // BFS from every vertex as src
  for (int s = 0; s < n; s++) {
    vi parent(n, -1);
    vi dist(n, -1);

    queue<int> q;

    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int v : adj[u]) {
        if (dist[v] == -1) {
          parent[v] = u;
          dist[v] = dist[u] + 1;
          q.push(v);
        } else if (v != parent[u]) {
          ans = min(ans, dist[u] + dist[v] + 1);
        }
      }
    }
  }

  if (ans == INF)
    ans = -1;

  cout << ans << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}
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

void dfs(ll u, vb &canReachN, vvll &revAdj) {
  canReachN[u] = 1;

  for (auto v : revAdj[u]) {
    if (canReachN[v] == false) {
      dfs(v, canReachN, revAdj);
    }
  }
}

int main() {
  ll n, m;
  cin >> n >> m;

  vvll edges;
  vvll revAdj(n + 1);

  for (int i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;

    // Bellman computes min total edgeWt
    // We want max edWt so multiply with -ve
    edges.push_back({u, v, -w});
    revAdj[v].push_back(u);
  }

  vll dist(n + 1, LINF);
  bool updated = false;

  dist[1] = 0;

  for (int i = 0; i < n - 1; i++) {
    updated = false;

    for (auto &e : edges) {
      ll u = e[0], v = e[1], w = e[2];

      if (dist[u] != LINF && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        updated = true;
      }
    }

    if (!updated)
      break;
  }

  vb canReachN(n + 1, false);
  dfs(n, canReachN, revAdj);

  for (auto &e : edges) {
    ll u = e[0], v = e[1], w = e[2];

    if (dist[u] != LINF && dist[u] + w < dist[v]) {
      if (canReachN[v]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  cout << -dist[n] << endl; // No -ve cycle reaches n

  return 0;
}
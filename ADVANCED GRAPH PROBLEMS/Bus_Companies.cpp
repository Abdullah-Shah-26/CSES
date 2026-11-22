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

  vll cost(m);
  for (auto &x : cost)
    cin >> x;

  vvi adj1(n); // city to company
  vvi adj2(m); // company to city

  // i = bus company idx
  for (int i = 0; i < m; i++) {

    // k = no of cities this company operates in
    int k;
    cin >> k;

    while (k--) {
      int u;
      cin >> u;
      u--;

      adj1[u].pb(i);
      adj2[i].pb(u);
    }
  }

  vll dist(n + m, LINF);
  vb vis(n + m, false);

  priority_queue<pll, vpll, greater<pll>> pq;

  dist[0] = 0;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (vis[u])
      continue;

    vis[u] = true;

    // u = city
    // city -> company incures cost
    if (u < n) {
      for (int i : adj1[u]) {
        int v = n + i;

        if (d + cost[i] < dist[v]) {
          dist[v] = d + cost[i];
          pq.push({dist[v], v});
        }
      }
    }

    // u = company hub
    // company hub to city, no cost since we paid ticket while entering the hub
    else {
      int i = u - n;

      for (int v : adj2[i]) {
        if (d < dist[v]) {
          dist[v] = d;
          pq.push({d, v});
        }
      }
    }
  }

  for (int i = 0; i < n; i++)
    cout << dist[i] << " ";

  cout << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}
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

Forward :
If multiple courses have indeg = 0
We select the course with smallest number first

Reverse :
If several have outdeg = 0 
Take the BIGGEST (gives earliest positions for 1, 2, 3...)

==========================
*/

void solve() {
  int n, m;
  cin >> n >> m;

  vvi adj(n);
  vi indeg(n, 0);

  // Reverse graph
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    // indeg[v]++;
    indeg[u]++;
    // adj[u].pb(v);
    adj[v].pb(u);
  }

  // priority_queue<int, vi>, greater<int>> pq; // Min heap
  priority_queue<int> pq; // Max heap

  for (int i = 0; i < n; i++)
    if (indeg[i] == 0)
      pq.push(i);

  vi order;

  while (!pq.empty()) {
    int u = pq.top();
    pq.pop();

    order.pb(u);

    for (int v : adj[u]) {
      indeg[v]--;

      if (indeg[v] == 0) {
        pq.push(v);
      }
    }
  }

  // Since we solved it reverse, we reverse again to get ans
  reverse(order.begin(), order.end());

  for (int u : order)
    cout << ++u << " ";

  cout << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}
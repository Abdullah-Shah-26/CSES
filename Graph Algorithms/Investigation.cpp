#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const ll INF = 4e18;

typedef pair<ll,int> P;

int main() {
  fastio();

  int n,m;
  cin >> n >> m;

  vector<vector<pair<int, ll>>> adj(n + 1);

  for(int i = 0; i < m; i++){
    int u,v;
    ll w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  // shortest distance
  vll dist(n + 1, INF);

  // no of shortest paths
  vi ways(n + 1, 0);

  // min edges among shortest paths
  vi mini(n + 1, INT_MAX);

  // max edges among shortest paths
  vi maxi(n + 1, INT_MIN);

  priority_queue<P, vector<P>, greater<P>> pq;

  dist[1] = 0;
  ways[1] = 1;
  mini[1] = 0;
  maxi[1] = 0;

  pq.push({0, 1});

  while(!pq.empty()){
    auto [d, u] = pq.top();
    pq.pop();

    if(d > dist[u]) continue;

    for(auto [v, w] : adj[u]){
      ll nd = d + w;

      // Better shorter path found
      if(nd < dist[v]){
        dist[v] = nd;
        ways[v] = ways[u];
        maxi[v] = maxi[u] + 1;
        mini[v] = mini[u] + 1;
        
        pq.push({dist[v], v});
      }

      // Another shortest path found
      else if(nd == dist[v]){
        ways[v] = (ways[v] + ways[u])%MOD;
        
        mini[v] = min(mini[v], mini[u] + 1);
        maxi[v] = max(maxi[v], maxi[u] + 1);
      }
    }
  }

  cout << dist[n] << " " << ways[n] << " " << mini[n] << " " << maxi[n] << endl;
  return 0;
}
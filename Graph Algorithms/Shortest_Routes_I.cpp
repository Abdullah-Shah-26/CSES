#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

typedef pair<ll,int> P;

int main() {
  fastio();
  
  int n,m;
  cin >> n >> m;

  vector<pair<int,ll>> adj[n + 1];

  for(int i = 0; i < m; i++){
    int u,v;
    ll w;
    cin >> u >> v >> w;
    adj[u].push_back({v,w});
  }

  priority_queue<P, vector<P>, greater<P>> pq; // [distance, node]
  vll dist(n + 1, LLONG_MAX);

  dist[1] = 0LL;
  pq.push({0,1});

  while(!pq.empty()){
    auto [dis, u] = pq.top();
    pq.pop();

    if(dis > dist[u]) continue;

    for(auto [v, edWt] : adj[u]){
      if(dis + edWt < dist[v]){
        dist[v] = dis + edWt;
        pq.push({dist[v], v});
      }       
    }
  }

  for(int i = 1; i <= n; i++){
    cout << dist[i] << " ";
  }

  return 0;
}
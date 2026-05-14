#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Edge{
  int u,v;
  ll w;
};

int main(){
  fastio();

  int n,m;
  cin >> n >> m;

  vector<Edge> edges;

  for(int i = 0; i < m; i++){
    int u, v;
    ll w;
    cin >> u >> v >> w;

    edges.push_back({u, v, w});
  }

  vector<ll> dist(n + 1, 0);
  vector<int> parent(n + 1, -1);

  int x = -1;

  // Bell-Man-Ford
  for(int i = 1; i <= n; i++){
    x = -1;

    for(auto &e : edges){
      int u = e.u;
      int v = e.v;
      ll w = e.w;

      if(dist[u] + w < dist[v]){
        dist[v] = dist[u] + w;
        parent[v] = u;
        x = v;
      }
    }
  }

  // No -ve cycle
  if(x == -1){
    cout << "NO" << endl;
    return 0;
  }

  // Move inside cycle
  for(int i = 0; i < n; i++){
    x = parent[x];    
  }

  int cur = x;

  vector<int> cycle;

  do {
    cycle.push_back(cur);
    cur = parent[cur];
  } while(cur != x);

  cycle.push_back(x);

  reverse(cycle.begin(), cycle.end());

  cout << "YES" << endl;

  for(int x : cycle){
    cout << x << " ";
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class DSU{
  public:
  
  vector<int> parent, sz;
  
  DSU(int n){
      parent.resize(n,0);
      sz.resize(n,1);
      
      for(int i = 1;i < n; i++) parent[i] = i;
  }
  
  int find(int node){
      
      while(node != parent[node]){
          parent[node] = parent[parent[node]];
          node = parent[node];
      }
      
      return node;
  }
  
  bool unite(int u,int v){
      u = find(u);
      v = find(v);
      
      if(u == v) return 0;
      
      if(sz[u] < sz[v]) swap(u,v);
      
      parent[v] = u;
      sz[u] += sz[v];
      
      return 1;
  }
};

int main() {
  fastio();

  int n, m;
  cin >> n >> m;

  DSU dsu(n+1);

  vector<vector<int>> edges(m);

  for(int i = 0; i < m; i++){
    int u,v,w;
    cin >> u >> v >> w; 

    edges[i].push_back(u);
    edges[i].push_back(v);
    edges[i].push_back(w);
  }

  auto cmp = [&](auto &a, auto &b){
    return a[2] < b[2];
  };

  sort(edges.begin(), edges.end(), cmp);

  int edgesUsed = 0;
  ll cost = 0;

  for(auto &e : edges){
    int u = e[0];
    int v = e[1];
    ll w = e[2];

    if(dsu.unite(u,v)){
      cost += w;
      edgesUsed++;
    }
  }

  // MST has n-nodes, and n-1 edges
  if(edgesUsed != n-1){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  cout << cost << endl;

  return 0;
}
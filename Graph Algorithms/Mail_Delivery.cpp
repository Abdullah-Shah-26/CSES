#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }
 
/* 
- Euler Circuit : 

- All edges traversed once
- St & End same
- St & End nodes should have even degree along with all other nodes
- For all edges to be traversed, graph should be connected
*/

vector<vector<pair<int,int>>> adj;
vector<int> deg;
vector<bool> seen; // To track visited edges
vector<int> path;

// DFS over edges
void dfs(int node){

  while(!adj[node].empty()){

    auto [nei, edgeId] = adj[node].back();
    adj[node].pop_back(); 

    if(seen[edgeId]) continue;
    
    seen[edgeId] = 1;
    dfs(nei);
  }
  path.push_back(node); // All edges of this node got exhausted, order finalized in euler ckt
}

int main() {
  fastio();

  int n,m;
  cin >> n >> m;

  adj.resize(n + 1);
  deg.resize(n + 1);

  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v,i}); // assigning edgeID
    adj[v].push_back({u,i});
    deg[u]++;
    deg[v]++;
  }

  for(int i = 1; i <= n; i++){
    if(deg[i] % 2 != 0){
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  seen.resize(m, false);
  path.clear();

  dfs(1);

  if(path.size() != m+1){
    cout << "IMPOSSIBLE" << endl;
  }
  else{
    for(int i = path.size() - 1; i >= 0; i--){
      cout << path[i] << ' ';
    }
    cout << endl;
  }

  return 0;
}
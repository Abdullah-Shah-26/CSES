#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

void dfs(int u, vector<int> adj[], vector<bool> &vis){
  vis[u] = 1;

  for(int v : adj[u]){
    if(!vis[v]){
      dfs(v, adj, vis);
    }
  }
}

int main() {
  fastio();

  int n,m;
  cin >> n >> m;

  vector<int> adj[n+1];
  vector<int> adjT[n+1];

  for(int i = 0; i < m; i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adjT[v].push_back(u);
  }

  vector<bool> vis(n+1,0);
  dfs(1, adj, vis);

  // If 1 fails to reach i
  for(int i = 1; i <= n; i++){
    if(!vis[i]){
      cout << "NO" << endl;
      cout << 1 << " " << i << endl;
      return 0;
    }
  }

  vis.assign(n + 1, 0);
  dfs(1, adjT, vis);

  // If any i fails to reach 1
  for(int i = 1; i <= n; i++){
    if(!vis[i]){
      cout << "NO" << endl;
      cout << i << " " << 1 << endl;
      return 0;
    }
  }

  cout << "YES" << endl;

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n,m;

bool bfs(int st, vector<bool> &vis, vector<int> &parent, vector<vector<int>> &adj){
  vis[st] = 1;
  
  queue<int> q;
  q.push(st);

  while(!q.empty()){
    int u = q.front();
    q.pop();

    if(u == n) return true;

    for(int v : adj[u]){
      if(!vis[v]){
        vis[v] = 1;
        parent[v] = u;
        q.push(v);
      }
    }
  }

  return false;
}

int main() {
  fastio();

  cin >> n >> m;

  vector<vector<int>> adj(n + 1);

  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> parent(n + 1, -1);
  vector<bool> vis(n + 1, 0);

  if(!bfs(1, vis, parent, adj)){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  //! Path Reconstruction
  int cur = n;
  vector<int>path;

  while(cur != -1){
    path.push_back(cur);
    cur = parent[cur];
  }

  reverse(path.begin(), path.end());

  cout << path.size() << endl;
 
  for(int i : path){
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
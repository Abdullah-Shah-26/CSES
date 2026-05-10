#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n,m;

//! BFS
bool bfs(int start, vector<int> &color, vector<vector<int>> &adj){
  queue<int> q;
  q.push(start);

  color[start] = 1;

  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(int v : adj[u]){
      if(color[v] == 0){
        color[v] = 3 - color[u];
        q.push(v);
      }
      else if(color[v] == color[u]){
        return false;
      }
    }
  }
  return true;
}

//! DFS
bool dfs(int u, vector<int>& color, vector<vector<int>>& adj) {

    for(int v : adj[u]) {

        // not colored yet
        if(color[v] == 0) {
            color[v] = 3 - color[u];

            if(!dfs(v, color, adj))
                return false;
        }

        // already colored → check conflict
        else if(color[v] == color[u]) {
            return false;
        }
    }

    return true;
}

int main() {
  fastio();

  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  
  for(int i = 0; i < m; i++){
    int u,v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> color(n + 1, 0); // 0 - not visited, 1 or 2 = team

  for(int i = 1; i <= n; i++){
    if(color[i] == 0){
      color[i] = 1; //* Assign color to stNode before dfs 
      if(!dfs(i, color, adj)){
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
    }
  }

  for(int i = 1; i <= n; i++){
    cout << color[i] << " "; 
  }
  cout << endl;

  return 0;
}
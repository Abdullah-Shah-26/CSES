#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n, m;
vector<vector<int>> adj;
vector<int> parent;
vector<bool> vis;
vector<bool> inRecStack;
int cycleSt = -1;
int cycleEnd = -1;
bool dfs(int u){
  vis[u] = 1;
  inRecStack[u] = 1;

  for(int v : adj[u]){
    if(!vis[v]){
      parent[v] = u;
      if(dfs(v)){
        return 1;
      }
    }
    else if(inRecStack[v]){
      cycleEnd = u;
      cycleSt = v;
    }
  }

  inRecStack[u] = 0;
  return false;
}

// Directed Graph Cycle : 

int main() {
  fastio();

  cin >> n >> m;
  adj.resize(n + 1);
  parent.resize(n + 1, -1);
  vis.resize(n + 1, 0);
  inRecStack.resize(n + 1, 0);

  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  for(int i = 1; i <= n; i++){
    if(!vis[i] && dfs(i)){
      break;
    }
  }

  if(cycleSt == -1){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  vector<int> cycle;
  cycle.push_back(cycleSt);

  int cur = cycleEnd;
  while(cur != cycleSt){
    cycle.push_back(cur);
    cur = parent[cur];
  }

  cycle.push_back(cycleSt);

  reverse(cycle.begin(), cycle.end());

  cout << cycle.size() << endl;
  for(int x : cycle){
    cout << x << " ";
  }

  return 0;
}
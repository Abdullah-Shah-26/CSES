#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n,m;
int cycleSt, cycleEnd;

bool dfs(int node, vector<bool> &vis, vector<int> &parent, vector<vector<int>> &adj){
  vis[node] = 1;

  for(auto &nei : adj[node]){
    if(!vis[nei]){
      parent[nei] = node;
        if(dfs(nei, vis, parent, adj)){
          return true;
        }
      }
    else if(parent[node] != nei){
      cycleSt = nei;
      cycleEnd = node;
      return true;
    } 
  }

  return false;
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

  vector<bool> vis(n+1,0);
  vector<int> parent(n+1,-1);

  cycleSt = -1, cycleEnd = -1;

  for(int i = 1; i <= n; i++){
    if(!vis[i]){
        if(dfs(i, vis, parent, adj)){
          break;
        }
      }
    }

  if(cycleSt == -1 || cycleEnd == -1){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  vector<int> cycle;
  
  int cur = cycleEnd;
  while(cur != cycleSt){
    cycle.push_back(cur);
    cur = parent[cur];
  } 
  
  cycle.push_back(cycleSt);
  reverse(cycle.begin(), cycle.end());
  cycle.push_back(cycleSt);

  cout << cycle.size() << endl;
  
  for(int i : cycle){
    cout << i << " ";
  }

  cout << endl;

  return 0;
}
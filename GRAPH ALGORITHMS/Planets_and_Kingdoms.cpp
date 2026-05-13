#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

vector<vector<int>> adj, adjT;
stack<int> st;
vector<bool> vis;

void dfs1(int u){
  vis[u] = 1;
  for(int v : adj[u]){
    if(!vis[v]){
      dfs1(v);
    }
  }
  st.push(u); // push while coming back
}

void dfs2(int u, vector<int> &comp){
  vis[u] = 1;
  comp.push_back(u);
  for(int v : adjT[u]){
    if(!vis[v]){
      dfs2(v, comp);
    }
  }
}

int main() {
  fastio();

  int n,m;
  cin >> n >> m;

  adj.resize(n + 1);
  adjT.resize(n + 1);
  vis.resize(n + 1, 0);
  
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adjT[v].push_back(u);
  }

  // Order by finish time
  for(int i = 1; i <= n; i++){
    if(!vis[i]){
      dfs1(i);
    }
  }

  fill(vis.begin(), vis.end(), 0);
  
  vi kingdom(n + 1, 0);
  int scc = 0;

  while(!st.empty()){
    int node = st.top(); 
    st.pop();

    if(!vis[node]){
      vi component;
      scc++;
      dfs2(node, component);

      for(int node : component){
        kingdom[node] = scc;
      }
    }
  }

  cout << scc << endl;
  for(int i = 1; i <= n; i++){
    cout << kingdom[i] << " ";
  }

  return 0;
}
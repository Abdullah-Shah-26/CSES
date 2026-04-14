#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n,m;

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if(size[a] < size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

//! DFS - Recursive
void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj){
  vis[u] = 1;

  for(auto &nei : adj[u]){
    if(!vis[nei])
      dfs(nei, vis, adj);
  }
}

//! DFS Iterative
void dfsIt(int start, vector<bool> &vis, vector<vector<int>> &adj){
  stack<int> st;
  
  st.push(start);
  vis[start] = 1;

  while(!st.empty()){
    int u = st.top();
    st.pop();

    for(int v : adj[u]){
      if(!vis[v]){
        vis[v] = 1;
        st.push(v);
      }
    }
  }
}


int main() {
  fastio();

  cin >> n >> m;
  DSU dsu(n + 1);

  vector<vector<int>> adj(n + 1);
  vector<bool> vis(n + 1, 0);

  for(int i = 0; i < m; i++){
    int u,v;
    cin >> u >> v;

    //* For DFS / BFS
    adj[u].push_back(v);
    adj[v].push_back(u);

    dsu.unite(u,v);
  }

  vector<int> leaders;
  for(int i = 1; i <= n; i++){
    // if(dsu.find(i) == i){
    //   leaders.push_back(i);
    // }

    if(!vis[i]){
      leaders.push_back(i); // representative of component
      dfsIt(i, vis, adj);
    }

  }

  // N nodes = N-1 Edges
  // N Comp = N-1 Edges
  cout << leaders.size() - 1 << endl;

  for(int i = 1; i < leaders.size(); i++){
    cout << leaders[i-1] << " " << leaders[i] << endl;
  }

  return 0;
}
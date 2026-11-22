#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n, m;
vector<vi> adj;
vi depth;
vi diff;

int up[200005][21];

// For computing depth
void dfs(int u, int p){
  up[u][0] = p;
  for(int v : adj[u]){
    if(v == p) continue;
    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
}

// Propogate children contribution upwards - Post Order DFS
void dfs2(int u, int p){
  for(int v : adj[u]){
    if(v == p) continue;
    dfs2(v, u);
    diff[u] += diff[v];
  }
}

int KthAncestor(int node, int k){
  for(int bit = 0; bit <= 20; bit++){
    if(k & (1 << bit)){
      if(node != -1){
        node = up[node][bit];
      }
    }
  }
  return node;
}

int f(int u, int v){
  if(depth[u] < depth[v]) swap(u,v);

  int diff = depth[u] - depth[v];

  // Lift u
  u = KthAncestor(u, diff);

  if(u == v) return u;

  for(int k = 20; k >= 0; k--){
    int kthAncestorU = up[u][k];
    int kthAncestorV = up[v][k];

    if(kthAncestorU == kthAncestorV) continue;

    u = kthAncestorU;
    v = kthAncestorV;
  }

  return up[u][0];
}

int main() {
  fastio();

  cin >> n >> m;
  adj.resize(n + 1, {});
  diff.resize(n + 1);
  depth.resize(n + 1);
  memset(up, -1, sizeof(up));

  for(int i = 0; i < n-1; i++){
    int u,v;
    cin >> u >> v;
    
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1,-1); // To calculate depth

  for(int k = 1; k <= 20; k++){
    for(int node = 1; node <= n; node++){
      if(up[node][k-1] != -1){
        up[node][k] = up[up[node][k-1]][k-1];
      }
    }
  }

  while (m--){
    int l, r;
    cin >> l >> r;

    diff[l]++;
    diff[r]++;

    int lca = f(l,r);
    diff[lca]--;
    
    int parentLCA = up[lca][0];
    if(parentLCA != -1){
      diff[parentLCA]--;
    }
  }
  
  dfs2(1,-1);

  for(int i = 1; i <= n; i++){
    cout << diff[i] << " ";
  }

  return 0;
}
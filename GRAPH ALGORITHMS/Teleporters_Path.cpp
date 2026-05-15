#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// Hierholzer Algorithm - Euler Path

int main() {
  fastio();

  int n,m;
  cin >> n >> m;

  vector<vi> adj(n + 1);
  vi indeg(n + 1), outdeg(n + 1);

  for(int i = 0; i < m; i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    indeg[v]++;
    outdeg[u]++;
  }

  // Start needs 1 extra outgoing edge
  // End needs 1 extra incoming edge

  if(outdeg[1] - indeg[1] != 1 || indeg[n] - outdeg[n] != 1){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  // In & out deg of other nodes must be same, cause we dont want to get stop in b/w
  for(int i = 2; i < n; i++){
    if(indeg[i] != outdeg[i]){
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  vi path;
  stack<int> st;
  st.push(1); // src

  while(!st.empty()){
    int u = st.top();
    
    // Use all outgoing edges of u
    if(!adj[u].empty()){
      int v = adj[u].back();
      adj[u].pop_back();
      st.push(v);
    }
    else{ // If all out going edges are exhausted, u is finalized in Euler ordering
      path.push_back(u);
      st.pop();
    }
  }

  reverse(path.begin(), path.end());

  // Euler path contains (m + 1) nodes

  // Check if we traversed all edges, st & end is correct or not
  if(path.size() != m + 1|| path.front() != 1 || path.back() != n){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  for(int x : path){
    cout << x << " ";
  }

  return 0;
}
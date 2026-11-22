#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

// DP on DAG

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main() {
  fastio();

  int n, m;
  cin >> n >> m;

  vi indeg(n + 1, 0);
  vector<int> adj[n + 1];

  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;

    indeg[v]++;
    adj[u].push_back(v);
  }

  queue<int> q;
  for(int i = 1; i <= n; i++){
    if(indeg[i] == 0){
      q.push(i);
    }
  }

  vi topo;
  while(!q.empty()){
    int u = q.front();
    q.pop();

    topo.push_back(u);

    for(int v : adj[u]){
      indeg[v]--;

      if(indeg[v] == 0){
        q.push(v);
      }
    }
  }

  // dp[u] = no of ways to reach u
  vll dp(n + 1, 0);
  dp[1] = 1;

  for(auto &u: topo){
    if(dp[u] == 0) continue;

    for(int v : adj[u]){
      dp[v] = (dp[v] + dp[u])% MOD;
    }
  }

  cout << dp[n] << endl;

  return 0;
}
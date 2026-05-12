#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n;
vector<vi> adj;
int dp[200005][2];

// dp[u][0] = best matching if u matches no child
// dp[u][1] = best matching if u matches exactly one child

int dfs(int u, int p){

  // u doesn't match any child
  for(int v : adj[u]){
    if(v == p) continue;

    dfs(v,u);

    // child chooes best independently
    dp[u][0] += max(dp[v][0],dp[v][1]);
  }

  // Try matching 1 child v
  for(int v : adj[u]){
    if(v == p) continue;

    // remove old best constribution of v
    int removeV = dp[u][0] - max(dp[v][0],dp[v][1]);
    // use edge(u,v)
    int useEdge  = 1 + dp[v][0];
    
    dp[u][1] = max(dp[u][1], removeV + useEdge);
  }

  return max(dp[u][0],dp[u][1]);
}

int main() {
  fastio();

  cin>>n;
  adj.resize(n + 1, {});

  for(int i = 0; i < n-1; i++){
    int u,v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  memset(dp, 0, sizeof(dp));
  cout << dfs(1, 0) << endl;
  return 0;
}
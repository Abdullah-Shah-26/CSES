#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main() {
  fastio();

  int n,m;
  cin >> n >> m;
  
  vll coins(n+1);
  for(int i = 1; i <= n; i++){
    cin >> coins[i];
  }

  vector<int> adj[n+1];

  for(int i = 0; i < m; i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  

  return 0;
}
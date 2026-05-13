#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;
const ll LINF = LLONG_MAX;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main() {
  fastio();

  int n,m,q;
  cin >> n >> m >> q;

  vector<vll> dist(n + 1, vll(n + 1, LINF));

  for(int i = 1; i <= n; i++){
    dist[i][i] = 0;
  }

  for(int i = 0; i < m; i++){
    int u,v;
    ll w;
    cin >> u >> v >> w;

    // If input gives diff edges wt for same pair (u,v) choose the one with smallest wt
    dist[u][v] = min(dist[u][v], w);
    dist[v][u] = min(dist[v][u], w);
  }

  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(dist[i][k] < LINF && dist[k][j] < LINF){
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }    
      }
    }
  }

  while(q--){
    int u,v;
    cin >> u >> v;
    
    if(dist[u][v] == LINF) cout << -1 << endl;
    else cout << dist[u][v] << endl;
  }

  return 0;
}
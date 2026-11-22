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

  vector<int> adj[n+1];
  vi indeg(n + 1);

  for(int i = 0; i < m; i++){
    int u,v;
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

  vi ans;
  int cnt = 0;

  while(!q.empty()){
    int u = q.front(); 
    q.pop();

    ans.push_back(u);
    cnt++;

    for(int v : adj[u]){
      indeg[v]--;

      if(indeg[v] == 0){
        q.push(v);
      }
    }
  }   


  if(cnt != n) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  for(auto x : ans){
    cout << x << " ";
  }

  return 0;
}
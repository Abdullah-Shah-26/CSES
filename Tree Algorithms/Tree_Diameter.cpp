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

pii bfs(int st){
  queue<int> q;
  q.push(st);

  vi dist(n+1,-1);
  dist[st] = 0;

  int farthest = st;
  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(int v : adj[u]){
      
      if(dist[v] == -1){
        dist[v] = 1 + dist[u];
        q.push(v);

        if(dist[v] > dist[farthest]){
          farthest = v;
        }
      } 
    }
  }

  return {farthest, dist[farthest]};
}

int main() {
  fastio();

  cin >> n;
  adj.resize(n+1, {});

  for(int i = 0; i < n-1; i++){
    int u,v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto [FN1, dist] = bfs(1);
  auto [FN2, diameter] = bfs(FN1);

  cout << diameter << endl;

  return 0;
}
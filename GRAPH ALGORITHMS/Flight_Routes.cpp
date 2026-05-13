#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;
const ll LINF = LLONG_MAX;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

typedef pair<ll,int> P;

int main() {
  fastio();

  int n,m,k;
  cin >> n >> m >> k;

  vector<pair<int,ll>> adj[n+1];

  for(int i = 0; i < m; i++){
    int u, v;
    ll w;
    cin >> u >> v >> w;
    adj[u].push_back({v,w});
  }

  // best[v] = stores k smallest distances to v
  // maxHeap -> top = worst among current k best 

  vector<priority_queue<ll>> best(n + 1);
  
  priority_queue<P, vector<P>, greater<P>> pq;

  pq.push({0,1});
  best[1].push(0);

  while(!pq.empty()){
    auto [dis, u] = pq.top();
    pq.pop();

    if(dis > best[u].top()) continue;

    for(auto [v, wt] : adj[u]){
      ll newDist = dis + wt;

      // Can we still insert more paths
      if((int)best[v].size() < k){
        best[v].push(newDist);
        pq.push({newDist, v});
      }

      // Else OverWrite the worst distance among k best
      else if(newDist < best[v].top()){
        best[v].pop();
        best[v].push(newDist);
        pq.push({newDist, v});
      }
    }
  }

  vll ans;

  while(!best[n].empty()){
    ans.push_back(best[n].top());
    best[n].pop();
  }

  sort(ans.begin(), ans.end());

  for(ll x : ans){
    cout << x << " ";
  }

  return 0;
}
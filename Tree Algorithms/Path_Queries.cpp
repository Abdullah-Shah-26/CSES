#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// Euler Tour + Fenwick Tree

class Fenwick{
  int n;
  vll bit;

  public: 
  Fenwick(int n): n(n), bit(n + 1, 0){}

  void update(int i, ll val){
    while(i <= n){
      bit[i] += val;
      i += i & -i;
    }
  }

  ll query(int i){
    ll sum = 0;
    while(i > 0){
      sum += bit[i];
      i -= i & -i;
    }
    return sum;
  }
};

int n,q;
vi val;
vi tin, tout;
vector<vi> adj;

int timer = 0;

void dfs(int u, int p){ // O(N)
  tin[u] = ++timer;

  for(int &v : adj[u]){
    if(v != p)
      dfs(v, u);
  }

  tout[u] = timer;
}

int main() {
  fastio();

  cin >> n >> q;

  val.resize(n + 1);
  tin.resize(n + 1);
  tout.resize(n + 1);
  adj.resize(n + 1);

  for(int i = 1; i <= n; i++)
    cin >> val[i];

  for(int i = 0; i < n-1; i++){
    int u, v;
    cin >> u >> v;
    
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1,-1);

  Fenwick ft(n + 2);

  // Initial subtree range additions
  for(int u = 1; u <= n; u++){
    ft.update(tin[u], val[u]);
    ft.update(tout[u]+1, -val[u]);
  }

  while(q--){ // O(Q * LogN)
    int type;
    cin >> type;

    if(type == 1){
      int s,x;
      cin >> s >> x;

      ll delta = x - val[s];
      val[s] = x;

      ft.update(tin[s], delta);
      ft.update(tout[s] + 1, -delta);
    } 
    else{
      int s;
      cin >> s;
      
      cout << ft.query(tin[s]) << endl;
    }
  }

  return 0;
}
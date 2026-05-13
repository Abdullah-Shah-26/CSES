#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class DSU{
  public:
  int n;
  int comp;
  int maxCompSize;
  vector<int> parent;
  vector<int> size;

  DSU(int n){
    comp = n;
    maxCompSize = 1;
    this->n = n;
    size.resize(n + 1, 1);
    parent.resize(n + 1);

    for(int i = 0; i <= n; i++) parent[i] = i;
  }

  int find(int x){
    return (x == parent[x]) ? x : parent[x] = find(parent[x]);
  }

  bool unite(int u,int v){
    u = find(u);
    v = find(v);

    if(u == v) return false; // No merge happened

    if(size[u] < size[v]) swap(u,v);

    parent[v] = u;
    size[u] += size[v];

    maxCompSize = max(maxCompSize, size[u]);
    comp--;
    return true;
  }

  int getNofComp(){
    return comp;
  }

  int findMaxCompSize(){
    return maxCompSize;
  }
};

int main() {
  fastio();

  int n,m;
  cin >> n >> m;

  DSU dsu(n);

  for(int i = 0; i < m; i++){
    int u,v;
    cin >> u >> v;

    dsu.unite(u,v);

    cout << dsu.getNofComp() << " " << dsu.findMaxCompSize() << endl;
  }

  return 0;
}
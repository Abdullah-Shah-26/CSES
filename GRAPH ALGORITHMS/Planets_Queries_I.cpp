#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// Binary Lifting

const int LOG = 30;
vector<vector<int>> up; 

void build(vector<int> &parent){
  int n = parent.size();
  up.assign(LOG, vector<int>(n));

  for(int j = 0; j < n; j++){
    up[0][j] = parent[j];
  }

  for(int i = 1; i < LOG; i++){
    for(int j = 0; j < n; j++){
      up[i][j] = up[i-1][up[i-1][j]];
    }
  }
}

int query(int node, int k){
  for(int bit = 0; bit < LOG; bit++){
    if(k & (1 << bit)){
      node = up[bit][node];
    }
  }
  return node;
}

int main() {
  fastio();

  int n, q;
  cin >> n >> q;

  vi parents(n);
  for(int i = 0; i < n; i++){
    cin >> parents[i];
    parents[i]--;
  }

  build(parents);

  while(q--){
    int node, k;
    cin >> node >> k;
    node--;

    cout << query(node, k) + 1 << endl; // converted to 1 based for o/p
  }

  return 0;
}
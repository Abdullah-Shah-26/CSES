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

  up.assign(n, vector<int> (LOG));

  // Filling 0th col, Immediate parent
  for(int node = 0; node < n; node++)
    up[node][0] = parent[node];

  for(int bit = 1; bit < LOG; bit++)
    for(int node = 0; node < n; node++)
      up[node][bit] = up[ up[node][bit - 1] ][bit - 1];
}

int query(int node, int k){
  for(int bit = 0; bit < LOG; bit++)
    if((k >> bit) & 1)
      node = up[node][bit];

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

    cout << query(node, k) + 1 << '\n'; // converted to 1 based for o/p
  }

  return 0;
}
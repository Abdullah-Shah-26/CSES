#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// order_of_key(k) : No of Elements < k
// *find_by_order(i) : Value at idx i (0 - based)

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvpi = vector<vector<pi>>;

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
static const auto fastio = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// ---------- Macros ----------
#define rv(a) for(auto &x:(a)) cin>>x
#define pv(a) do{ for(const auto &x:(a)) cout<<x<<' '; cout<<'\n'; }while(0)
#define rm(mat) for(auto &r:(mat)) for(auto &x:(r)) cin>>x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define nl do{ cout << '\n'; }while(0)

// TC : (N+Q)LogN
// SC : O(NLogN)

int n,q;
int up[200005][21];
vi adj[200005];
vi depth(200005,0);

void dfs(int u, int p){ // TC = O(N)
  for(auto &v : adj[u]){
    if(v == p) continue;
    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
}

int kthAncestor(int node, int k){ 
  // Jumping from LSB -> MSB
  for(int bit = 0; bit <= 20; bit++){
    if(k & (1 << bit)){
      if(node != -1){
        node = up[node][bit];
      }
    }
  }

  return node;
}

int f(int u, int v){
  if(depth[u] < depth[v]) swap(u,v);

  int diff = depth[u] - depth[v];

  // Lifting deeper node to equalize depth
  u = kthAncestor(u, diff);

  if(u == v) return u; // One of them is LCA

  // Else lca is present above, now lift both together
  for(int k = 20; k >= 0; k--){
    int kthAncestorOfU = up[u][k];
    int kthAncestorOfV = up[v][k];

    // If ancestor is same, LCA lies somewhere below, since we are checking highest ancestor's first
    if(kthAncestorOfU == kthAncestorOfV) continue;

    u = kthAncestorOfU;
    v = kthAncestorOfV;
  }

  return up[u][0]; // LCA is now the direct parent of u or v, since we moved u,v up
}

// ---------- Solve ---------
void solve(){
  cin >> n >> q;

  memset(up, -1, sizeof(up));

  for(int u = 2; u <= n; u++){
    int v;
    cin >> v;

    up[u][0] = v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // precompute depth
  dfs(1,-1);

  // preprocessing to fill matrix completely
  for(int k = 1; k <= 20; k++){ // NlogN
    for(int node = 1; node <= n; node++){
      if(up[node][k-1] != -1)
        up[node][k] = up[up[node][k-1]][k-1];
    }
  }

  while(q--){ // QLogN
    int u,v;
    cin >> u >> v;

    cout << f(u,v) << endl;
  }
}

// ---------- Main ----------
int main(){
  solve();
  return 0;
}
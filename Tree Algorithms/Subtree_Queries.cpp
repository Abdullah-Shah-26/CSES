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

struct Fenwick{
  int n;
  vll bit;

  Fenwick(int n){
    this->n = n;
    bit.resize(n + 1, 0);
  }

  void update(int i, ll val){
    while(i <= n){
      bit[i] += val;
      i += (i & -i);
    }
  }

  ll query(int i){
    ll sum = 0;
    while(i > 0){
      sum += bit[i];
      i -= (i & -i);
    }
    return sum;
  }
};

int n,q;
vvi adj;
vll val;
vi tin;
vi tout;
int timer = 0;

void dfs(int u, int p){
  tin[u] = ++timer;
  for(int v : adj[u]){
    if(v == p) continue;
    dfs(v, u);
  }
  tout[u] = timer;
}

// ---------- Solve ---------
void solve(){
  cin >> n >> q;

  adj.resize(n + 1, {});
  val.resize(n + 1);
  tin.resize(n + 1);
  tout.resize(n + 1);

  for(int i = 1; i <= n; i++)
    cin >> val[i];

  for(int i = 0; i < n-1; i++){
    int u,v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs(1,-1);

  Fenwick ft(n + 2);

  // Fenwick initialization
  for(int i = 1; i <= n; i++){
    ft.update(tin[i], val[i]);
  }

  while(q--){
    int type;
    cin >> type;

    if(type == 1){
      ll s,x;
      cin >> s >> x;;

      ll delta = x - val[s];
      ft.update(tin[s], delta); 

      val[s] = x;
    }
    else{
      ll s;
      cin >> s;
      
      // Range sum = pref[r]  - pref[l-1]]
      cout << ft.query(tout[s]) - ft.query(tin[s] - 1) <<  endl; 
    }
  }
}

// ---------- Main ----------
int main(){
    // int t; 
    // cin >> t;
    // while(t--)
       solve();
    return 0;
}
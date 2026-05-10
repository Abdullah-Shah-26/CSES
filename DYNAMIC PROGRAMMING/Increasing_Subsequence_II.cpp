#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// TC = O(N Log N) | SC = O(N)

vi a;

class Fenwick{
  public:

  int n;
  vll bit;

  Fenwick(int n) : n(n), bit(n+1, 0) {}

  void update(int i, int delta){
    while(i <= n){
      bit[i] += delta;
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

int main() {
  fastio();

  int n;
  cin >> n;
  a.assign(n,0);

  for(int i = 0; i < n; i++) cin >> a[i];

  
  vi vals = a; // Co-ordinate compress
  
  sort(begin(vals), end(vals));
  
  vals.erase(unique(begin(vals), end(vals)), vals.end());

  Fenwick ft(vals.size());

  ll ans = 0;
  
  for(int i = 0; i < n; i++){
    int id = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;

    ll dp = (1 + ft.query(id - 1)) % MOD;

    ft.update(id, dp);

    ans = (ans + dp) % MOD; 
  }

  cout << ans << endl;

  return 0;
} 

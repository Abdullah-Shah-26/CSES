#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vpii = vector<pii>;
using vvpii = vector<vector<pii>>;
using vpll = vector<pll>;
using vvpll = vector<vector<pll>>;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

static const auto fastio = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

int main() {

  ll n, q;
  cin >> n >> q;

  vll a(n);
  for(ll &x : a)
    cin >> x;

  vll pref(n + 1, 0);
  pref[0] = 0; 

  for(int i = 1; i <= n; i++)
    pref[i] = pref[i - 1] + a[i - 1];

  while(q--){
    int l, r;
    cin >> l >> r;
    cout << pref[r] - pref[l - 1] << endl;
  }

  return 0;
}
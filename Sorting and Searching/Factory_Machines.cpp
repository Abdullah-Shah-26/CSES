#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

ll n,t;
vll a;

bool check(ll x){
  ll productsMade = 0;

  for(auto &k : a){
    productsMade += x/k;

    if(productsMade >= t) return 1;
  }

  return 0;
}

int main() {
  fastio();

  cin >> n >> t;

  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  ll maxMachineTime = *max_element(begin(a), end(a));

  ll low = 1, high = t * maxMachineTime;
  ll ans = high;

  while(low <= high){
    ll mid = (low + high) >> 1;

    if(check(mid)){
      ans = mid;
      high = mid-1;
    }
    else{
      low = mid +1;
    }
  }

  cout << ans << endl;
  
  return 0;
}
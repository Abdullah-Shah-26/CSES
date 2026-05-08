#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

ll n,k;
vll a;

bool check(ll x){
  ll subarr = 1;
  ll sum = 0;

  for(auto &i : a){
    if(i > x) return false;

    if(sum + i > x){
      subarr++;
      sum = i;
    }
    else{
      sum += i;
    }
  }

  return subarr <= k;
}

int main() {
  fastio();

  cin >> n;
  cin >> k;

  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  ll low = 1, high = 2e18;
  ll ans = high;

  while(low <= high){
    ll mid = (low + high) >> 1;

    if(check(mid)){
      ans = mid;
      high = mid-1;
    }
    else{
      low = mid + 1;
    }
  }

  cout << ans << endl;

  return 0;
}
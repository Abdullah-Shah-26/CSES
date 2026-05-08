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

// pref[r] - pref[l-1] == k
// pref[l-1] = pref[r] - k 

int main() {
  fastio();

  cin >> n >> k;

  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  
  map<ll,ll> freq;
  freq[0] = 1;

  ll pref = 0;
  ll ans = 0;

  for(int i = 0; i < n; i++){
    pref += a[i];
      
    ans += freq[pref - k];

    freq[pref]++;
  }

  cout << ans << endl;
  
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main()
{
  fastio();

  ll n;
  cin >> n;
  vll a(n);

  map<ll,ll> freq;

  for (int i = 0; i < n; i++){
    cin >> a[i];
    freq[a[i]]++;
  }

  ll res = 1;
  for (auto &[val, f] : freq)
    res = (res * (f + 1)) % MOD;
  
  res = (res - 1 + MOD) % MOD;

  cout << res << endl;

  return 0;
}
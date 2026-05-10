#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main() {
  fastio();

  int n,k;
  cin >> n >> k;

  ll x,a,b,c;

  cin >> x >> a >> b >> c;

  // x1 = x
  // x2 = (ax1 + b) % c
  // x3 = (ax2 + b) % c

  vll arr;
  arr.push_back(x);

  for(int i = 1; i < n; i++){
    ll newElem = (a * arr[i-1] + b) % c;
    arr.push_back(newElem);
  }

  // xor(l...r) = pref[r] - pref[l-1]
  int cur = 0;
  for(int i = 0; i < k; i++)  
    cur ^= arr[i];
  
  int ans = cur;

  for(int i = k; i < n; i++){
    cur ^= arr[i-k]; // l leaves
    cur ^= arr[i]; // r comes

    ans ^= cur;
  }

  cout << ans << endl;

  return 0;
}
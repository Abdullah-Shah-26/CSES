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

  int n,m;
  cin >> n >> m;
  
  ll k;
  cin >> k;

  vll a(n), b(m);
  
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];

  sort(begin(a), end(a));
  sort(begin(b), end(b));

  int i = 0, j = 0;
  ll cnt = 0;

  while(i < n && j < m){
    if(a[i] - k <= b[j] && b[j] <= a[i] + k){
      cnt++;
      i++;
      j++;
    }
    else if(b[j] < a[i] - k){
      j++;
    }
    else if(b[j] > a[i] + k){
      i++;
    }
  }

  cout << cnt << endl;

  return 0;
}
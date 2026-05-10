#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

void add(ll x, vi &cnt, ll &OR){
  while(x){
    int b = __builtin_ctzll(x); 

    if(cnt[b] == 0)
      OR |= (1LL << b);

    cnt[b]++;

    x &= (x - 1);
  }
}

void removeBits(ll x, vi &cnt, ll &OR){
  while(x){
    int b = __builtin_ctzll(x);
    cnt[b]--;

    if(cnt[b] == 0)
      OR ^= (1LL << b);

    x &= (x-1);
  }
}

int main() {
  fastio();

  int n,k;
  cin >> n >> k;
  
  ll x,a,b,c;
  cin >> x >> a >> b >> c;

  //! Edge Case : 
  if(k == 1){
    int cur = x;
    int ans = 0;

    for(int i = 0; i < n; i++){
      ans ^= cur;
      cur = (1LL * a * cur + b) % c;
    }

    cout << ans << endl;
    return 0;
  }

  deque<int> window;
  int cur = x;

  // 1st window
  vi cnt(32,0);
  ll OR = 0;

  for(int i = 0; i < k; i++){
    add(cur, cnt, OR);
    window.push_back(cur);

    int next = ((1LL * a * cur) + b)%c;
    cur = next;
  }

  ll ans = OR; 
  
  for(int i = k; i < n; i++){

    int left = window.front();
    window.pop_front();

    // Remove Left
    removeBits(left, cnt, OR);

    // Add Right
    add(cur, cnt, OR);
    window.push_back(cur);

    ans ^= OR;

    int next = ((1LL * a * cur) + b) % c;
    cur = next;
  }

  cout << ans << endl;

  return 0;
}
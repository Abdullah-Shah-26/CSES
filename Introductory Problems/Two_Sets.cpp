#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Greedy - Take the best choice first

int main() {
  fastio();

  ll n;
  cin >> n;

  ll total = 1LL * n * (n + 1)/2;

  if(total & 1){
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;

  ll target = total/2;
  vi a,b;
  vector<bool> used(n + 1, 0);

  for(ll i = n; i >= 1; i--){
    if(i <= target){
      a.push_back(i);
      used[i] = 1;
      target -= i;
    }
  }

  for(int i = 1; i <= n; i++){
    if(!used[i])
      b.push_back(i);
  }


  cout <<  a.size() << endl;
  for(int x : a)
    cout << x << " ";

  cout << endl;

  cout << b.size() << endl;
  for(int x : b)
    cout << x << " ";

  cout << endl;

  return 0;
}
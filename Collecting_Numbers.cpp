#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

ll n;
vll pos;

int main() {
  fastio();

  cin >> n;

  pos.resize(n + 1);

  for(int i = 1; i <= n; i++){
    ll x;
    cin >> x;
    pos[x] = i;
  }  

  ll rounds = 1;

  for(int i = 2; i <= n; i++){
    // If x is found before x-1, we need one more round to get it
    if(pos[i] < pos[i-1]) rounds++;
  }

  cout << rounds << endl;

  return 0;
}
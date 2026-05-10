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

  vll arr;
  arr.push_back(x);

  for(int i = 1; i < n; i++){
    ll newElem = (a * arr[i-1] + b) % c;
    arr.push_back(newElem);
  }

  ll sum = 0;

  for(int i = 0; i < k; i++){
    sum += arr[i];
  }

  ll cur = sum;

  for(int i = k; i < n; i++){
    sum -= arr[i-k];
    sum += arr[i];

    cur ^= sum;
  }

  cout << cur << endl;

  return 0;
}
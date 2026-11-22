#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fastio();

  ll n;
  cin >> n;

  ll have = 0;
  for (int i = 0; i < n - 1; i++) {
    ll x;
    cin >> x;
    have += x;
  }

  ll need = (n * (n + 1)) / 2;

  cout << need - have << endl;

  return 0;
}
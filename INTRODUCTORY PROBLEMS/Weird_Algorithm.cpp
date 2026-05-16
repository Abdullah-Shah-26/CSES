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

  while (n != 1) {
    cout << n << " ";

    if (n & 1) {
      n = n * 3 + 1;
    } else {
      n = n / 2;
    }
  }
  cout << 1 << endl;

  return 0;
}
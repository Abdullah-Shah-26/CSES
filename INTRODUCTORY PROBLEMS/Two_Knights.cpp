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

  int N;
  cin >> N;

  for (ll n = 1; n <= N; n++) {
    ll size = n * n;
    ll allWays = size * (size - 1) / 2;
    ll badWays = 0;
    badWays += 8 * (n - 4) * (n - 4);
    badWays += 6 * (n - 4) * 4;
    badWays += 4 * (n - 3) * 4;
    badWays += 3 * 8;
    badWays += 2 * 4;
    badWays /= 2;
    cout << allWays - badWays << endl;
  }

  return 0;
}
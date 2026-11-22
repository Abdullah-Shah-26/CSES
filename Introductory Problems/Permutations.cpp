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

  int n;
  cin >> n;

  vi a;

  for (int i = 1; i <= n; i += 2) {
    a.push_back(i);
  }

  for (int i = 2; i <= n; i += 2) {
    a.push_back(i);
  }

  if (n == 4) {
    a = {3, 1, 4, 2};
  }

  for (int i = 0; i < (int)a.size() - 1; i++) {
    if (abs(a[i] - a[i + 1]) == 1) {
      cout << "NO SOLUTION" << endl;
      return 0;
    }
  }

  for (int x : a) {
    cout << x << ' ';
  }

  return 0;
}
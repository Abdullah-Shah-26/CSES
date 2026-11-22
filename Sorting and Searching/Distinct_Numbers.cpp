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

  int n;
  cin >> n;

  vi a(n);

  for(int i = 0; i < n; i++)
    cin >> a[i];

  sort(a.begin(), a.end());

  int distinct = unique(a.begin(), a.end()) - a.begin();

  cout << distinct << endl;

  return 0;
}
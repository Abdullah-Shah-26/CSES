#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vpii = vector<pii>;
using vvpii = vector<vector<pii>>;
using vpll = vector<pll>;
using vvpll = vector<vector<pll>>;
using ull = unsigned long long;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

vector<ull> fact;

void solve() {
  int type;
  cin >> type;

  if (type == 1) {
    int n;
    ull k;
    cin >> n >> k;

    k--; // Converting to 0 based

    vi a; // available
    for (int i = 1; i <= n; i++)
      a.push_back(i);

    for (int pos = 0; pos < n; pos++) {
      ull blockSize = fact[n - pos - 1];
      ull idx = k / blockSize;

      cout << a[idx]; // First guy of that block
      if (pos + 1 != n)
        cout << " ";

      a.erase(a.begin() + idx);
      k %= blockSize;
    }

    cout << endl;
  } else {
    int n;
    cin >> n;

    vi perm(n);
    for (auto &x : perm)
      cin >> x;

    vi a; // available
    for (int i = 1; i <= n; i++)
      a.push_back(i);

    ull rank = 1; // ans is 1 indexed

    for (int pos = 0; pos < n; pos++) {
      int idx = 0;

      while (a[idx] != perm[pos])
        idx++;

      rank += (ull)idx * fact[n - pos - 1];
      a.erase(a.begin() + idx);
    }

    cout << rank << endl;
  }
}

int main() {

  fact.assign(21, 0);
  fact[0] = 1;
  for (ll i = 1; i <= 20; i++)
    fact[i] = fact[i - 1] * i;

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
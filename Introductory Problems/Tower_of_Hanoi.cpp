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

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

vpii moves;

void solve(int n, int from, int to) {
  if (n == 0)
    return;

  int other = 6 - from - to;

  solve(n - 1, from, other);
  moves.push_back({from, to});
  solve(n - 1, other, to);
}

int main() {

  int n;
  cin >> n;

  solve(n, 1, 3);

  cout << moves.size() << endl;
  for (auto [a, b] : moves) {
    cout << a << " " << b << endl;
  }

  cout << endl;

  return 0;
}
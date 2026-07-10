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
const int N = 1000005;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

int main() {

  vll divisors(N + 1);

  for (int i = 1; i <= N; i++)
    for (int j = i; j <= N; j += i)
      divisors[j]++;

  int n;
  cin >> n;

  while (n--) {
    ll x;
    cin >> x;
    cout << divisors[x] << endl;
  }

  return 0;
}
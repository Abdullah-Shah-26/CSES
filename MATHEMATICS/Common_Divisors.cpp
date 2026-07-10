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

const int N = 1e6;
vi freq(N + 1, 0);

int main() {

  int n;
  cin >> n;

  vi a(n);
  for (int &x : a) {
    cin >> x;
    freq[x]++;
  }

  for (int g = N; g >= 1; g--) { // O(N)
    int cnt = 0;
    for (int multiple = g; multiple <= N; multiple += g) { // O(N/G)
      cnt += freq[multiple];

      if (cnt >= 2) {
        cout << g << endl;
        return 0;
      }
    }
  }

  return 0;
}
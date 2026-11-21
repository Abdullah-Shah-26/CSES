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
const ll LINF = 4e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

vi buildLPS(string &s) {
  int n = s.size();

  vi lps(n, 0);

  for (int i = 1, j = 0; i < n;) {
    if (s[i] == s[j]) {
      lps[i] = j + 1;
      i++;
      j++;
    } else if (j > 0) {
      j = lps[j - 1];
    } else
      i++;
  }

  return lps;
}

int main() {
  string s;
  cin >> s;

  int n = s.size();

  vi lps = buildLPS(s);
  vi ans;

  int len = lps[n - 1];
  while (len > 0) {
    ans.push_back(len);
    len = lps[len - 1];
  }

  sort(begin(ans), end(ans));

  for (auto &x : ans)
    cout << x << ' ';

  return 0;
}
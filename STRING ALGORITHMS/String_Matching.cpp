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

vi buildLPS(string &p) {
  int m = p.size();
  vi lps(m, 0);

  for (int i = 1, j = 0; i < m;) {
    if (p[i] == p[j]) {
      lps[i] = j + 1;
      i++;
      j++;
    } else if (j > 0) {
      j = lps[j - 1];
    } else {
      i++;
    }
  }

  return lps;
}

int cntMatches(string &s, string &p, vi &lps) {
  int n = s.size();
  int m = p.size();

  int ans = 0;

  for (int i = 0, j = 0; i < n;) {
    if (s[i] == p[j]) {
      i++;
      j++;
    } else if (j > 0) {
      j = lps[j - 1];
    } else {
      i++;
    }

    if (j == m) {
      ans++;
      j = lps[j - 1];
    }
  }

  return ans;
}

int main() {

  string s, p;
  cin >> s >> p;

  vi lps = buildLPS(p);

  cout << cntMatches(s, p, lps) << endl;

  return 0;
}
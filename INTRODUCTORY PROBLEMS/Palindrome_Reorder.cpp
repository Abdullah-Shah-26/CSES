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

int main() {

  string s;
  cin >> s;

  int freq[26] = {};

  for (char &ch : s) {
    freq[ch - 'A']++;
  }

  int odd = 0;

  for (auto f : freq) {
    if (f & 1)
      odd++;
  }

  if (odd > 1) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  string left = "";
  char mid = 0;

  for (int i = 0; i < 26; i++) {
    if (freq[i] & 1)
      mid = char('A' + i);

    left += string(freq[i] / 2, char('A' + i));
  }

  string right = left;
  reverse(begin(right), end(right));

  cout << left;

  if (mid)
    cout << mid;

  cout << right << endl;

  return 0;
}
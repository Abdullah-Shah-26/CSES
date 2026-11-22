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

  string s;
  cin >> s;

  int n = s.size();

  int freq = 0;
  int maxFreq = 0;

  for (int i = 0; i < n; i++) {
    if (i != 0 && s[i] == s[i - 1]) {
      freq++;
    } else {
      freq = 1;
    }
    maxFreq = max(maxFreq, freq);
  }

  cout << maxFreq << endl;

  return 0;
}
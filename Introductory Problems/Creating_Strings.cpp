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

bool nextPerm(string &s){
  int n = s.size();

  int i = n-2; 

  // Find 1st dip from right
  while(i >= 0 && s[i] >= s[i+1]){
    i--;
  }

  if(i < 0) return false; // Already largest perm

  int j = n-1; // Find just larger guy on right;

  while(s[j] <= s[i]){
    j--;
  }

  swap(s[i],s[j]);
  reverse(s.begin() + i + 1, s.end()); 

  return true;
}

int main() {
  fastio();

  string s;
  cin >> s;

  vector<string> perms;
  sort(s.begin(), s.end());
  perms.push_back(s);

  while (nextPerm(s)) {
    perms.push_back(s);
  }

  cout << perms.size() << endl;
  for (string &s : perms) {
    cout << s << endl;
  }

  return 0;
}
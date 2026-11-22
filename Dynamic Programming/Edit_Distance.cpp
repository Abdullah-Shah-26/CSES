#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }
int n,m;

int dp[5001][5001];

int f(int i, int j, string &s1, string &s2){
  if(i < 0) return j + 1;
  if(j < 0) return i + 1;

  if(dp[i][j] != -1) return dp[i][j];

  if(s1[i] == s2[j]){
    return f(i-1, j-1, s1, s2);
  }

  return dp[i][j] =  1 + min({f(i, j-1, s1, s2), f(i-1, j, s1, s2), f(i-1, j-1, s1, s2)});
}

int main() {
  fastio();

  string s1, s2;
  cin >> s1 >> s2;

  n = s1.size();
  m = s2.size();

  if(n == 0){
    cout << m << endl;
    return 0;
  }
  else if(m == 0){
    cout << n << endl;
    return 0;
  }
  else if(s1 == s2) {
    cout << 0 << endl;
    return 0;
  } 
  
  memset(dp, -1, sizeof(dp));

  cout << f(n-1,m-1,s1,s2) << endl;

  return 0;
}
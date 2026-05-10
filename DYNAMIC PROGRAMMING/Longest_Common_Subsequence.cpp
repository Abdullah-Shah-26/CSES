#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main() {
  fastio();

  int n,m;
  cin >> n >> m;

  vi a(n), b(n);
  for(int &x: a) cin >> x;
  for(int &x: b) cin >> x;

  vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      
      if(a[i-1] == b[j-1]){
        dp[i][j] = 1 + dp[i-1][j-1];
      }
      else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }

    }
  }

  int len = dp[n][m];

  //* LCS Reconstruction
  vi lcs(len);

  int i = n, j = m, idx = len - 1;

  while(i > 0 && j > 0){
    if(a[i-1] == b[j-1]){
      lcs[idx] = a[i-1];
      idx--;
      i--;
      j--;
    }
    else{
      if(dp[i-1][j] > dp[i][j-1]){
        i--;
      }
      else{
        j--;
      }
    }
  }

  cout << len << "\n";
  for(int x : lcs) cout << x << " ";
  cout << "\n";

  return 0;
}
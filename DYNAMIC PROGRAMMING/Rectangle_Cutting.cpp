#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Partition DP

//* TC = O(N*M (N + M))

int main() {
  fastio();

  int n, m;
  cin >> n >> m;

  vector<vector<int>> dp(n + 1, vector<int> (m + 1, INT_MAX));

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){

      // Base Case : Already Square
      if(i == j){
        dp[i][j] = 0;
        continue;
      }

      // Vertical Cuts
      for(int k = 1; k < j; k++){
        // +1 cause we have cut & split it now
        dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]); 
      }

      // Horizontal Cuts
      for(int k = 1; k < i; k++){
        dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
      }

    }
  }

  cout << dp[n][m] << endl;

  return 0;
}
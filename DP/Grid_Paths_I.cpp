#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n;

/* 
int dp[1001][1001];

int dfs(int i, int j, vector<vector<char>> &grid){
  if(i >= n || j >= n || grid[i][j] == '*') return 0; // Invaid Cell
  if(i == n-1 && j == n-1) return 1; // Destination Reached 

  if(dp[i][j] != -1) return dp[i][j];

  int down = dfs(i + 1, j, grid);
  int right = dfs(i, j + 1, grid);

  return dp[i][j] = (down + right) % MOD;
}
*/

int main() {
  fastio();

  cin >> n;

  vector<vector<char>> grid(n, vector<char>(n));

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> grid[i][j];
    }
  }

  if(grid[0][0] == '*'){
    cout << 0 << endl;
    return 0;
  }
   
  // memset(dp, -1, sizeof(dp));
  // cout << dfs(0,0,grid) << endl;

/*   
  vector<vector<int>> dp(n, vector<int> (n, 0));
  dp[0][0] = (grid[0][0] == '.') ? 1 : 0; 

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){

      if(i == 0 && j == 0) continue;

      if(grid[i][j] == '*') {// Invalid Cell
        dp[i][j] = 0;
        continue;
      }

      int top = 0, left = 0;

      if(i > 0){
        top = dp[i-1][j];
      }
      if(j > 0){
        left = dp[i][j-1];
      }

      dp[i][j] = (top + left) % MOD; 
    }
  }

  cout << dp[n-1][n-1] << endl;
 */

vector<int> prev(n, 0);

prev[0] = (grid[0][0] == '.');

for (int i = 0; i < n; i++) {
    vector<int> cur(n, 0);

    for (int j = 0; j < n; j++) {

        if (i == 0 && j == 0){ //! Avoids OverRiding baseCase
          cur[j] = 1;
          continue;
        }

        if (grid[i][j] == '*') {
            cur[j] = 0;
            continue;
        }

        int top = 0, left = 0;

        if (i > 0)
            top = prev[j];

        if (j > 0)
            left = cur[j-1];

        cur[j] = (top + left) % MOD;
    }

    prev = cur;
}

cout << prev[n-1] << endl;

return 0;
}
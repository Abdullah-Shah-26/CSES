#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n,m;

/* //! Recursion + Memo
int dp[100001][101];

//* prev = previous Value
int f(int i, int prev, vi &a){
  if(i == n) return 1;

  if(dp[i][prev] != -1) return dp[i][prev];

  ll ans = 0;

  if(a[i] != 0){ //* Forced to take this element
    if(abs(a[i] - prev) <= 1){
      ans = f(i + 1, a[i], a);
    }
    else{ 
      ans = 0;
    }
  }
  else{
    for(int v = prev - 1; v <= prev + 1; v++){
      if(v >= 1 && v <= m){
        ans = (ans + f(i + 1, v, a)) % MOD;
      }
    }
  }

  return dp[i][prev] = ans; 
}

int main() {
  fastio(); 

  cin >> n >> m;

  vi a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  memset(dp, -1, sizeof(dp));

  ll ans = 0;

  if(a[0] != 0){
    ans = f(1, a[0], a);
  }
  else{
    for(int v = 1; v <= m; v++){ //* Try all possible starts
      ans = (ans + f(1, v, a)) % MOD;
    }
  }

  cout << ans << endl;

  return 0;
} */

int main(){
  fastio();
  
  cin >> n >> m;

  vi a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  vector<vector<int>> dp(n, vector<int> (m + 1, 0));

  // Base Case
  // Case 1 :  
  if(a[0] != 0){ // Forced to take this element
    dp[0][a[0]] = 1;
  }
  else{ // Try all starts from 1 to m - Free Choice
    for(int i = 1; i <= m; i++){
      dp[0][i] = 1;
    }
  }

  for(int i = 1; i < n; i++){
    for(int prev = 1; prev <= m; prev++){ // prev = prev Value

      if(dp[i-1][prev] == 0) continue;

      if(a[i] != 0){ //* Forced
        if(abs(a[i] - prev) <= 1){
          dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][prev]) % MOD;
        }
      }
      else{
        for(int v = prev-1; v <= prev+1; v++){
          if(v >= 1  && v <= m){
            dp[i][v] = (dp[i][v] + dp[i-1][prev]) % MOD;
          }
        }
      }
    
    }
  }

  int ans = 0;

  for(int v = 1; v <= m; v++){
    ans = (ans + dp[n-1][v]) % MOD;
  }

  cout << ans << endl;

  return 0;
}
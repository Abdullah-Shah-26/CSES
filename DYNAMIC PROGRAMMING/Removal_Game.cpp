#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Interval DP
/* 
int main() {
  fastio();

  int n;
  cin >> n;

  vi a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  vector<vector<ll>> dp(n, vector<ll> (n, 0)); 

  //* dp[i][j] = maxScore I can get from [l....r]

  for(int len = 1; len <= n; len++){
    // len = j - i + 1
    // j = len + i - 1
    for(int i = 0; len + i - 1 < n; i++){
      int j = len + i - 1;

    // BaseCase : 
     if(len == 1){
      dp[i][j] = a[i];
     }
      
     else if(len == 2){
      dp[i][j] = max(a[i],a[j]);
     }

     else{
      dp[i][j] = max(a[i] + min(dp[i+2][j], dp[i+1][j-1]), a[j] + min(dp[i+1][j-1], dp[i][j-2]));
     }
    }
  }

  cout << dp[0][n-1] << endl;

  return 0;
} */

//! Recursion + Memo

ll dp[5001][5001];

int f(int i,int j, vi &a){
  if(i > j) return 0;

  if(i == j) return a[i];

  if(dp[i][j] != -1) return dp[i][j];

  ll pickL = a[i] + min(f(i+2, j, a) , f(i+1, j-1, a));
  ll pickR = a[j] + min(f(i+1, j-1, a), f(i, j-2, a));

  return max(pickL, pickR);
}

int main(){
  fastio();

  int n;
  cin >> n;

  vi a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  memset(dp, -1, sizeof(dp));

  cout << f(0, n-1, a) << endl;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// int f(int n){
//   if(n == 0) return 1;
//   if(n < 0) return 0;

//   if(dp[n] != -1) return dp[n];

//   int ways = 0;
//   for(int i = 1; i <= 6; i++){
//     ways =(ways +  f(n-i))%MOD;
//   }

//   return dp[n] =  ways;
// }


//! TC = O(N*6) | SC = O(N)

int main(){
  int n;
  cin >> n;

  // dp[i] = no of ways to make sum = i
  vector<int> dp(n + 1, 0);
  dp[0] = 1;

  for(int i = 1; i <= n; i++){ 
    for(int j = 1; j <= 6; j++){
      if(i - j >= 0){
        dp[i] = (dp[i] + dp[i-j])%MOD;
      }
    }
  }

  cout << dp[n] << endl;
}
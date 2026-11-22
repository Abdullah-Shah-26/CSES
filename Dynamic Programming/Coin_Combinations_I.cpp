#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! This is permutation - Order Matters [1,2] != [2,1]

//! Using Loop
// int dp[1000001];

// int f(int sum, vector<int>& coins) {
//     if (sum == 0) return 1;
//     if (dp[sum] != -1) return dp[sum];

//     int ways = 0;
//     for (int coin : coins) {
//         if (sum >= coin) {
//             ways = (ways + f(sum - coin, coins)) % MOD;
//         }
//     }
//     return dp[sum] = ways % MOD;
// }

//! Without Loop
// int f(int i, int sum, vector<int> &a){
//   if(sum == 0) return 1;
//   if(sum < 0) return 0;

//   int ways = 0;
//   if(sum - a[i] >= 0){ // Take
//     ways = (ways + f(0, sum - a[i], a)); // Again reset idx to 0 
//   }

//   ways = (ways + f(i + 1, sum - a[i], a)); // Skip

//   return ways;
// }


//! TC = O(Sum * N) | SC = O(Sum)

int main(){
  fastio();

  int n, sum;
  cin >> n >>sum;

  vi a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  } 

  // memset(dp, -1, sizeof(dp));
  // cout << f(sum, a) << endl;

  vector<int> dp(sum + 1, 0);
  dp[0] = 1;
  
  for(int i = 1; i <= sum; i++){
    for(int coin : a){
      if(i - coin >= 0){
        dp[i] = (dp[i] + dp[i-coin])%MOD;
      }
    }
  }

  cout << dp[sum] << endl;
}
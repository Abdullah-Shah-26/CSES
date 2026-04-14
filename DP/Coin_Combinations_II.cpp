#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! This is combination - Order doesnt matter - [1,2] == [2,1]

//! Without Loop

// int f(int i,int sum, vi &a){
//   if(sum == 0) return 1;
//   if(i == a.size()) return 0;

//   int ways = 0;
//   if(sum - a[i] >= 0){ // Take
//     ways = (ways + f(i, sum - a[i], a)) % MOD;
//   }

//   ways = (ways + f(i + 1, sum, a)) % MOD; // Skip

//   return ways;
// }

//! Using Loop

// int dp[101][1000001];

// int f(int i, int sum, vi &a){

//   if(sum == 0) return 1;
//   if(dp[i][sum] != -1) return dp[i][sum];

//   int ways = 0;

//   for(int j = i; j < a.size(); j++){ // Start from i not 0 i.e Skip choice is considered
//     if(sum - a[j] >= 0) // Take
//       ways = (ways + f(j, sum - a[j], a)) % MOD; // Stay at j, reuse allowed 
//   }

//   return dp[i][sum] = ways;
// }


int main(){
  fastio();

  int n,x;
  cin >> n >> x;

  vi a(n);

  for(int i = 0; i < n; i++)
    cin >> a[i];

  // memset(dp, -1, sizeof(dp));

  // dp[i] = No of ways to make sum = s
  vector<int> dp(x + 1, 0);
  dp[0] = 1;
  
  // Order doesnt matter - Fix Coins
  for(int coin : a){
    for(int s = coin; s <= x; s++){
      dp[s] = (dp[s] + dp[s - coin]) % MOD; 
    }
  }
  cout << dp[x] << endl;
}
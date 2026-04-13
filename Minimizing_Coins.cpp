#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Rec + Memo ---> TC = O(N * Sum) | SC = O(N * Sum)

// int dp[101][1000001];

// int f(int i, int sum, vector<int> &a){

//   if(sum == 0) return 0;

//   if(i == a.size()) return INT_MAX;

//   if(dp[i][sum] != -1)  return dp[i][sum];

//   int skip = f(i + 1, sum, a);
//   int take = INT_MAX;

//   if(sum - a[i] >= 0){
//     int res = f(i, sum - a[i], a);

//     if(res != INT_MAX){
//       take = 1 + res;
//     }
//   }

//   return dp[i][sum] = min(take, skip);
// }

//! Bottom Up --->  TC = O(N * Sum) | SC = O(Sum)

int main(){
  fastio();

  int n, sum;
  cin >> n >> sum;

  vi a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  // dp[i] = min coins required to make sum i
  vector<int> dp(sum + 1, INT_MAX);
  dp[0] = 0;
  
  for(int i = 1; i <= sum; i++){
    for(int coin : a){
      if(i - coin >= 0 && dp[i-coin] != INT_MAX){
        dp[i] = min(dp[i], 1 + dp[i-coin]);
      }
    }
  }

  cout << (dp[sum] == INT_MAX ? -1 : dp[sum]) << endl;
}
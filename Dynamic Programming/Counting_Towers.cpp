#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int MAXN = 1e6;
ll dp[MAXN+1][2];

int main() {
  fastio();   
  memset(dp, 0, sizeof(dp));

  // dp[i][0] = No of ways to build tower of ht i ending with vertical blocks of width = 1
  // dp[i][1] = No of ways to build tower of ht i ending with horizontal blocks of width = 2

  // Base Case
  dp[1][0] = 1; // 1 way to place vertical dominos at ht = 1
  dp[1][1] = 1; // 1 way to place horizontal domino at ht = 1

  for(int i = 2; i <= MAXN; i++){
    dp[i][0] = (4*dp[i-1][0] + dp[i-1][1]) % MOD;
    dp[i][1] = (2*dp[i-1][1] + dp[i-1][0]) % MOD;
  }

  int t;
  cin>>t;

  while(t--){
    int n;
    cin >> n;
    ll result = (dp[n][0] + dp[n][1]) % MOD;
    cout << result << endl;
  }

  return 0;
}
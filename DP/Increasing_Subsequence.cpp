#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

ll n;
vll a;
ll ans; 

// ll dp[200001][200002];

// int solve(int i, int prevIdx){
//   if(i == n) return 0;

//   if(dp[i][prevIdx + 1] != -1)
//     return dp[i][prevIdx + 1];

//   ll skip = solve(i + 1, prevIdx);

//   ll take = 0;
//   if(prevIdx == -1 || a[prevIdx] < a[i]){
//     take = 1 + solve(i + 1, i);
//   }

//   return dp[i][prevIdx + 1] = max(take, skip);
// }

//! LIS - Patience Sorting 

int main() {
  fastio();

  cin >> n;

  a.assign(n,0);

  for(int i = 0; i < n; i++)
      cin >> a[i];


  // memset(dp, -1, sizeof(dp));
 
  // cout << solve(0, -1) << endl;

  vector<int> tails;

  for (int x : a) {
      auto it = lower_bound(tails.begin(), tails.end(), x);

      if (it == tails.end()) tails.push_back(x);
      else *it = x;
  }

  cout << tails.size() << endl;

  return 0;
}
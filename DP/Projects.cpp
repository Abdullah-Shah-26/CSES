#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

/*
! Classical Weighted Interval Scheduling + Binary Search + DP

- Choosing non overlapping projects, maximize reward

! Approach 1 :
- Sort By End
- dp[i] = best ans using first i projects
- Textbook style greedy interval problem

*/

/*
ll solve(int i, vector<vector<int>> &a, vll &dp){
  if(i < 0) return 0; // No reward

  if(dp[i] != -1) return dp[i];

  ll skip = solve(i - 1, a, dp);

  int st = a[i][1];
  int reward = a[i][2];

  // a[i] = {end, st, reward}
  // We need end < st
  // So just do lower bound which finds first end >= st & do a -1

  int j = lower_bound(a.begin(), a.begin() + i, vi{st, 0, 0}) - a.begin() - 1;

  ll take = reward + solve(j, a, dp);

  return dp[i] = max(take,skip);
}

int main() {
  fastio();

  int n;
  cin >> n;

  vector<vector<int>> a(n, vector<int> (3, 0));

  for(int i = 0; i < n; i++){
    int s, e, p;
    cin >> s >> e >> p;

    a[i] = {e, s, p};
  }

  sort(a.begin(), a.end());

  vll dp(n, -1);

  cout << solve(n-1, a, dp) << endl;

  return 0;
}
*/

/*
ll solve(int i, vector<vector<int>> &a, vll &dp, int n){
  if(i >= n) return 0;

  if(dp[i] != -1) return dp[i];

  ll skip = solve(i + 1, a, dp, n);

  int end = a[i][1];
  int reward = a[i][2];

  // Find next project with start just > current end
  int next = upper_bound(a.begin() + i + 1, a.end(), vector<int>{end, INT_MAX, INT_MAX}) - a.begin();

  ll take = reward + solve(next, a, dp, n);

  return dp[i] = max(take, skip);
}
*/

int main()
{
  fastio();

  int n;
  cin >> n;

  vector<vector<int>> a(n, vector<int>(3, 0));

  for (int i = 0; i < n; i++)
    cin >> a[i][0] >> a[i][1] >> a[i][2]; // st, end, reward

  sort(begin(a), end(a));

  // vll dp(n, -1);
  // cout << solve(0, a, dp, n) << endl;

  vi starts(n);
  for(int i = 0; i < n; i++)  
    starts[i] = a[i][0];

  vll dp(n + 1, 0);

  for(int i = n-1; i >= 0; i--){
    
    int end = a[i][1];
    int reward = a[i][2];
    
    // Find first st > current end
    int next = upper_bound(starts.begin(), starts.end(), end) - starts.begin();

    ll skip = dp[i + 1];
    ll take = reward + dp[next];

    dp[i] = max(take, skip);
  }

  cout << dp[0] << endl;

  return 0;
}
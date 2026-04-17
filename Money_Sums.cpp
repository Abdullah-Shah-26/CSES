#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n;

//! Like DP on DAG

/* 
bool vis[101][100001];
void dfs(int i, int sum, vector<int> &coins, set<int>& st){
  
  if(vis[i][sum]) return;
  
  vis[i][sum] = 1;

  if(i == n){
    if(sum != 0){ // because we dont have any no as 1 so sum can never be 1
      st.insert(sum);
    }
    return;
  }

  dfs(i + 1, sum, coins, st);   // Skip
  dfs(i + 1, coins[i] + sum, coins, st);   // Take
}

int main() {
  fastio();

  cin >> n;

  vi coins(n);
  set<int> st;
  
  for(int i = 0; i < n; i++) cin >> coins[i];

  memset(vis, 0, sizeof(vis));
  dfs(0, 0, coins, st);

  cout << (int)st.size();
  cout << endl;

  for(auto &it : st){
    cout << it << " ";
  }
  cout << endl;

  return 0;
}
*/

//! Bottom Up + Space Optimized

int main(){
  cin >> n;
  
  int sum = 0;

  vector<int> coins(n);
  
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    coins[i] = x;
    sum += x;
  }

  vector<vector<bool>> dp(n + 1, vector<bool> (sum + 1, 0));
  vector<int> ans;

  //* dp[i][s] = can i form s using first i coins
  dp[0][0] = 1;

  for(int i = 1; i <= n; i++){
    for(int s = 0; s <= sum; s++){

      // Skip
      dp[i][s] = dp[i-1][s];

      // Take
      if(s >= coins[i-1]){
        dp[i][s] = dp[i][s] || dp[i-1][s-coins[i-1]];
      }
    }
  }

  for(int s = 1; s <= sum; s++){
    if(dp[n][s])
      ans.push_back(s);
  }

  cout << ans.size() << endl;
  for(int x : ans){
    cout << x << " ";
  }

  return 0;
}
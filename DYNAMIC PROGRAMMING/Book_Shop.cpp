#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n,x;

/* 
int dp[1001][100001];
int f(int i, int budget, vector<int> &price, vector<int> &pages){
  
  if(i == n) return 0;
  if(budget == 0) return 0;

  if(dp[i][budget] != -1) return dp[i][budget];

  int skip = f(i + 1, budget, price, pages);

  int take = 0;
  if(budget >= price[i]){
    take = pages[i] + f(i + 1, budget - price[i], price, pages);
  }

  return dp[i][budget] = max(take, skip);
}
 */

int main() {
  fastio();

  cin >> n >> x;

  vector<int> price(n, 0), pages(n, 0);

  for(int i = 0; i < n; i++) cin >> price[i];
  for(int i = 0; i < n; i++) cin >> pages[i];

  // memset(dp, -1, sizeof(dp));
  // cout << f(0, x, price, pages);

  // vector<vector<int>> dp(n + 1, vector<int> (x + 1, 0)); // Max pages using budget x upto index i
  vector<int> prev(x + 1, 0); 

  for(int i = 0; i < n; i++){ //! TC = (N * X) | SC = O(N)
    for(int b = x; b >= 1; b--){

      int skip = prev[b];

      int take = 0;
      if(b >= price[i]){
        take = pages[i] + prev[b - price[i]];
      }

      prev[b] = max(take, skip);
    }
  }

  cout << prev[x] << endl;

  return 0;
}
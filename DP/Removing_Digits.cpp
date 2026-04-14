#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Concept : DAG - DP Optimal  | BFS Level Wise 

//! Recursion + Memo | TC = O(N LogN)  || SC = O(N)
/* 
int dp[1000001];
int f(int x){
  if(x == 0) return 0;

  if(dp[x] != -1) return dp[x];

  int steps = INT_MAX;

  int temp = x;
  while(temp > 0){
    int digit = temp % 10;
    temp /= 10;

    if(digit == 0) continue; // Avoids self loops, infinite recursion

    steps = min(steps, 1 + f(x - digit)); // Try all digits of x
  }

  return dp[x] = steps;
} */

//! BFS - Layer Wise - TC = O(N * (digits in N)) | SC = O(N)
/* 
int bfs1(int n){
  vector<bool> vis(n + 1,0);
  queue<int> q;

  q.push(n);
  vis[n] = 1;

  int steps = 0;

  while(!q.empty()){
    int sz = q.size();

    while(sz--){
      int x = q.front();
      q.pop();

      if(x == 0) return steps; //* Reached Destination

      int temp = x;
      while(temp > 0){ //* Try all digits in x
        int digit = temp % 10;
        temp /= 10;

        if(digit == 0) continue;

        int newX = x - digit;

        if(!vis[newX]){
          vis[newX] = 1;
          q.push(newX);
        }
      }
    }

  steps++;
  }

  return -1;
} */

//! BFS using dist array - TC = O(N * (digits in N)) = O(N LogN) || SC = O(N)  

/* 
int bfs2(int n){ 
  vector<int> dist(n + 1, -1);  // min steps to reach i
  
  queue<int> q;
  q.push(n);
  dist[n] = 0;

  while(!q.empty()){
    int x = q.front();
    q.pop();

    if(x == 0) return dist[x];

    int temp = x;
    while(temp > 0){
      int digit = temp % 10;
      temp /= 10;

      if(digit == 0) continue; 

      int newX = x - digit;

      if(dist[newX] == -1){ // The first time we reach a newX we reach with min steps since edwt = 1
        dist[newX] = dist[x] + 1; 
        q.push(newX);
      }
    }
  }
  return -1;
}
*/

int main() {
  fastio();

  int n;
  cin >> n;

  // memset(dp, -1, sizeof(dp));
  // cout << f(n) << endl;
  // cout << bfs2(n) << endl;

  vector<int> dp(n + 1, INT_MAX);
  // dp[i] = min steps to reduce i -> 0

  dp[0] = 0;

  for(int i = 1; i <= n; i++){
    int temp = i;

    while(temp > 0){
      int digit = temp%10;
      temp /= 10;

      if(digit == 0) continue;
      
      dp[i] = min(dp[i], 1 + dp[i - digit]);
    }
  }


  cout << dp[n] << endl;

  return 0;
}
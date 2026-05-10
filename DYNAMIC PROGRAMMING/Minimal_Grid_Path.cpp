#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N^2) | SC = O(N^2)
//* BFS + Pruning

int main() {
  fastio();

  int n;
  cin >> n;

  vector<vector<char>> grid(n, vector<char>(n));
  vector<vector<bool>> vis(n, vector<bool> (n, 0));

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> grid[i][j];
    }
  }

  string ans = "";

  queue<pair<int,int>> q;

  q.push({0,0});
  ans += grid[0][0];

  while(!q.empty()){
    int sz = q.size();

    vector<pair<int,int>> touched;
    vector<pair<int,int>> next;

    while(sz--){
      auto [i,j] = q.front();
      q.pop();

      if(i + 1 < n && (!vis[i+1][j])){
        vis[i+1][j] = 1;
        touched.push_back({i+1,j});
        next.push_back({i+1,j});  
      }

      if(j + 1 < n && !vis[i][j+1]){
        vis[i][j+1] = 1;
        touched.push_back({i, j+1});
        next.push_back({i, j+1});
      }
    }

    if(!next.empty()){
      char best = 'Z';
      for(auto [i,j] : next){
        best = min(best, grid[i][j]);
      }

      ans += best;

      for(auto [i,j] : next){
        if(best == grid[i][j]){
          q.push({i,j});
        }
      }
    }

    for(auto [i,j] : touched){
      vis[i][j] = 0; 
    }
  }

  cout << ans << endl;

  return 0;
}
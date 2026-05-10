#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int row[4] = {0,0,1,-1};
int col[4] = {1,-1,0,0};

int n,m;

/* 
void bfs(int i, int j, vector<vector<char>>&grid){
  
  queue<pair<int,int>> q;
  q.push({i, j});
  grid[i][j] = '#';

  while(!q.empty()){
    auto [r,c] = q.front();
    q.pop();

    for(int k = 0; k < 4; k++){
      int nr = r + row[k];
      int nc = c + col[k];

      if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.'){
        grid[nr][nc] = '#';
        q.push({nr,nc});
      }
    }
  }
}
 */

void dfs(int r, int c, vector<vector<char>> &grid){
  grid[r][c] = '#';

  for(int k = 0; k < 4; k++){
    int nr = r + row[k];
    int nc = c + col[k];

    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.'){
      dfs(nr, nc, grid);
    }
  }
}

int main() {
  fastio();

  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m));

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> grid[i][j];
    }
  }

  int rooms = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == '.'){
        // bfs(i, j, grid);
        dfs(i, j, grid);
        rooms++;
      }
    }
  }

  cout << rooms << endl;

  return 0;
}
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

// L R D U
int row[4] = {0, 0, 1, -1};
int col[4] = {-1, 1, 0, 0};
int direction[4] = {'L', 'R', 'D', 'U'};

int stRow, stCol, endRow, endCol;
int n, m;

bool bfs(vector<vector<char>> &grid, vector<vector<pair<int, int>>> &parent, vector<vector<char>> &how)
{

  queue<pair<int, int>> q;
  q.push({stRow, stCol});

  grid[stRow][stCol] = '#';
  parent[stRow][stCol] = {-1,-1};

  while (!q.empty())
  {
    auto [r, c] = q.front();
    q.pop();

    if(r == endRow && c == endCol) return true;

    for (int k = 0; k < 4; k++)
    {
      int nr = r + row[k];
      int nc = c + col[k];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m && (grid[nr][nc] == '.' || grid[nr][nc] == 'B'))
      {
        parent[nr][nc] = {r, c};
        how[nr][nc] = direction[k];
        grid[nr][nc] = '#';
        q.push({nr,nc});
      }
    }
  }

  return false;
}

int main()
{
  fastio();

  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m));
  stRow = -1, stCol = -1, endRow = -1, endCol = -1;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];

      if (grid[i][j] == 'A')
      {
        stRow = i, stCol = j;
      }
      if (grid[i][j] == 'B')
      {
        endRow = i, endCol = j;
      }
    }
  }

  vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1})); // To Trace Back Path
  vector<vector<char>> how(n, vector<char>(m));                                  // Stores Direction LRDU

  if(bfs(grid, parent, how) == false){
    cout << "NO" << endl;
    return 0;
  }

  //! Path Reconstruction
  string path;
  pair<int,int> cur = {endRow, endCol};

  while(cur != make_pair(stRow, stCol)){
    path.push_back({how[cur.first][cur.second]});
    cur = parent[cur.first][cur.second];
  }

  reverse(path.begin(), path.end());

  cout << "YES" << endl;
  cout << path.size() << endl;
  cout << path << endl;

  return 0;
}
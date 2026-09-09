#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vpii = vector<pii>;
using vvpii = vector<vector<pii>>;
using vpll = vector<pll>;
using vvpll = vector<vector<pll>>;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

ll ans = 0;

/*
void f(int row, vector<string> &grid) {
  if (row == 8) {
    ans++;
    return;
  }

  for (int col = 0; col < 8; col++) {
    if (grid[row][col] == '.') {
      bool safe = true;

      // Above rows
      for (int r = 0; r < row; r++) {
        if (grid[r][col] == 'Q') {
          safe = false;
          break;
        }
      }

      // Upper Left diagonal
      for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
        if (grid[r][c] == 'Q') {
          safe = false;
          break;
        }
      }

      // Upper right diagonal
      for (int r = row - 1, c = col + 1; r >= 0 && c < 8; r--, c++) {
        if (grid[r][c] == 'Q') {
          safe = false;
          break;
        }
      }

      if (safe) {
        grid[row][col] = 'Q';
        f(row + 1, grid);
        grid[row][col] = '.';
      }
    }
  }
}
*/

void f(int row, vector<string> &grid, vector<bool> colAttacked,
       vector<bool> diag1Attacked, vector<bool> diag2Attacked) {
  if (row == 8) {
    ans++;
    return;
  }

  for (int col = 0; col < 8; col++) {
    if (grid[row][col] == '.' && !colAttacked[col] &&
        !diag1Attacked[row + col] && !diag2Attacked[row - col + 7]) {
      grid[row][col] = 'Q';
      colAttacked[col] = 1;
      diag1Attacked[row + col] = 1;
      diag2Attacked[row - col + 7] = 1;
      f(row + 1, grid, colAttacked, diag1Attacked, diag2Attacked);
      grid[row][col] = '.';
      colAttacked[col] = 0;
      diag1Attacked[row + col] = 0;
      diag2Attacked[row - col + 7] = 0;
    }
  }
}

int main() {
  int n = 8;

  vector<string> grid(n);

  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }

  f(0, grid, vector<bool>(8), vector<bool>(15), vector<bool>(15));

  cout << ans << endl;

  return 0;
}
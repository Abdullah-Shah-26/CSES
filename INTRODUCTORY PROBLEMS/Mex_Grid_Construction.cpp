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
const ll LINF = 4e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

int main() {

  int n;
  cin >> n;

  vvi mat(n, vi(n));

  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      set<int> st;

      for (int i = 0; i < row; i++)
        st.insert(mat[i][col]);

      for (int j = 0; j < col; j++)
        st.insert(mat[row][j]);

      int x = 0;

      while (st.count(x))
        x++;

      mat[row][col] = x;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;

  return 0;
}
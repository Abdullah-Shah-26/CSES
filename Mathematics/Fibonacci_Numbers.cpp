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

vvll mul(vvll &A, vvll &B) {
  int n = A.size();

  vvll C(n, vll(n, 0));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;

  return C;
}

vvll matExpo(vvll base, ll exp) {
  int n = base.size();

  vvll ans(n, vll(n, 0));

  for (int i = 0; i < n; i++)
    ans[i][i] = 1;

  while (exp) {
    if (exp & 1)
      ans = mul(ans, base);

    base = mul(base, base);
    exp >>= 1;
  }

  return ans;
}

int main() {

  ll n;
  cin >> n;

  if(n == 0){
    cout << 0 << endl;
    return 0;
  }

  vvll T = {{1,1},{1,0}};
  vvll res = matExpo(T, n-1);

  cout << res[0][0] << endl;

  return 0;
}
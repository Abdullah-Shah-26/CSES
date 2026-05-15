#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int n, m;
vector<vector<int>> adj;
vector<vector<ll>> memo;

ll dfs(int mask, int u) {
  if (mask == (1 << n) - 1) {
    return u == n - 1; // reached all nodes and u is last node
  }

  ll &ans = memo[mask][u];

  if (ans != -1)
    return ans;

  ans = 0;

  for (int v : adj[u]) {
    if (mask & (1 << v))
      continue;

    int nextMask = mask | (1 << v);

    ans = (ans + dfs(nextMask, v)) % MOD;
  }

  return ans;
}

// BitMask DP

int main() {
  fastio();

  cin >> n >> m;

  adj.resize(n);
  memo.assign(1 << n, vector<ll>(n, -1));

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
  }

  // cout << dfs(1 << 0, 0) << endl;

  vector<vector<ll>> dp(1 << n, vector<ll>(n, 0)); // dp contains all theoritically possible states
  dp[1 << 0][0] = 1; // 1 way to reach city 0

  for (int mask = 0; mask < (1 << n); mask++) {
    for (int u = 0; u < n; u++) {
      if (!(mask & (1 << u)))
        continue; // First visit u then v

      ll ways = dp[mask][u];
      if (ways == 0)
        continue; // No ways to reach u itself

      for (int v : adj[u]) {
        if (mask & (1 << v)) continue;
        int nextMask = mask | (1 << v);

        dp[nextMask][v] = (dp[nextMask][v] + ways) % MOD;
      }
    }
  }

  cout << dp[(1 << n) - 1][n - 1] << endl;

  return 0;
}
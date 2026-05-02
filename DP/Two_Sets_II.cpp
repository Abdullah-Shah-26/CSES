#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll total = 1LL * n * (n + 1) / 2;

    if (total & 1) {
        cout << 0 << '\n';
        return 0;
    }

    int target = total / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    // dp[s] = no of ways to make sum = s
    // use 1..n-1 to avoid double counting partitions
    for (int num = 1; num < n; ++num) {
        for (int s = target; s >= num; --s) {
            dp[s] = (dp[s] + dp[s - num]) % MOD;
        }
    }

    cout << dp[target] << '\n';
    return 0;
}
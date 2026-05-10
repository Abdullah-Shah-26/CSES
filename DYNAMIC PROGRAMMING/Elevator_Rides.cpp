#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;
const ll INF = 1e18;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main() {
  fastio();

  int n;
  ll x;

  cin >> n;
  cin >> x;

  vll w(n, 0);

  for(int i = 0; i < n; i++)
    cin >> w[i];

  ll N = (1 << n); // Total Subsets

  vector<pair<ll,ll>> dp = {N, {INF,INF}};
  
  dp[0] = {1, 0};


  for(int mask = 0; mask < N; mask++){

    auto [rides, lastWt] = dp[mask];

    for(int i = 0; i < n; i++){

      if(mask & (1 << i)) continue;

      int newMask = mask | (1 << i);

      ll newRides = rides;
      ll newLastWt;

      if(lastWt + w[i] <= x){
        newLastWt = lastWt + w[i];
      }
      else{
        newRides = rides + 1;
        newLastWt = w[i];
      }


      dp[newMask] = min(dp[newMask], {newRides, newLastWt}); 
    }
  }

  cout << dp[N-1].first << endl;

  return 0;
}
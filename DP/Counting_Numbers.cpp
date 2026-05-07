#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// tight, prev, curIdx, lz
ll dp[2][11][20][2];

ll f(string &s, bool tight, ll prev, ll idx, ll lz){

  if(idx == (int)s.size()) return 1; // 1 valid ans

  if(dp[tight][prev][idx][lz] != -1) return dp[tight][prev][idx][lz];

  ll lb = 0;
  ll ub = (tight == 1) ? s[idx] - '0' : 9; // Upper Bound

  ll res = 0;

  for(ll d = lb; d <= ub; d++){

    bool newTight = (tight & (d == ub));
    bool newLz = (lz & (d == 0));
    ll newPrev = newLz ? 10 : d;

    // No 2 adj digits can be same 
    if(!newLz && d == prev) continue;

    res += f(s, newTight, newPrev, idx + 1, newLz);
  }

  return dp[tight][prev][idx][lz] = res;
}

ll solve(ll a, ll b){
  
  string r = to_string(b);

  // i = current idx
  // tight = (1 == bounded) (0 == unbounded)
  // prev = prevNo, if we didnt choose any prevNo keep it 10, since we have digits form 1-9 we use 10 as flag that we didnt choose any past digit
  // lz = leading zeros

  memset(dp, -1, sizeof(dp));
  
  ll resR = f(r, 1, 10, 0, 1);

  if(a == 0)
    return resR;

  string l = to_string(a-1);

  memset(dp, -1, sizeof(dp));

  ll resL = f(l, 1, 10, 0, 1);

  return resR - resL;
}

int main() {
  fastio();

  ll a,b;
  cin >> a >> b;

  cout << solve(a,b) << endl;

  return 0;
}
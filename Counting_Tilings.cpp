#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n,m;
int tilings[1001][1<<10]; // m * n 

void fillCol(int col, int idx, int curMask, int nextMask){

  if(idx == n){
    tilings[col + 1][nextMask] = (tilings[col + 1][nextMask] + tilings[col][curMask]) % MOD;
    return;
  }

  if((curMask) & (1 << idx))
    fillCol(col, idx + 1, curMask, nextMask);

  else{
    fillCol(col, idx + 1, curMask, nextMask | (1 << idx));

  }

}

int main() {
  fastio();

  cin >> n >> m;
  
  for(int col = 0; col < m; col++){
    for(int mask = 0; mask < (1 << n); mask++){
      if(tilings[col][mask] > 0){
        
      }
    }
  }


  return 0;
}
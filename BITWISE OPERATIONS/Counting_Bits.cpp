#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main() {
  fastio();

  ll n;
  cin >> n;

  ll totalSetBits = 0;

  for(int bit = 0; bit < 60; bit++){
    ll blockSize = 1LL << (bit + 1); // 2^(k + 1)
    ll onesPerBlock = 1LL << bit; // 2^k

    ll totalNos = n + 1; // Including 0's for easier block math

    ll completeBlocks = totalNos/blockSize; 
    ll remainingNos = totalNos % blockSize; // partial block left out

    ll onesFromCompleteBlocks = onesPerBlock * completeBlocks;
    ll onesFromRemainingPart = max(0LL, remainingNos - onesPerBlock);

    totalSetBits += onesFromCompleteBlocks + onesFromRemainingPart;
  }

  cout << totalSetBits << endl;

  return 0;
}
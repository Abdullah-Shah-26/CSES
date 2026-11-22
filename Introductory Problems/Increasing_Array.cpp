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

  int n;
  cin >> n;

  vi a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  ll ops = 0;

  for(int i = 1; i < n; i++){
    // while(i != 0 && a[i-1] > a[i]){
    //   a[i]++;
    //   ops++;
    // } 

    if(a[i-1] > a[i]){
      ops += a[i-1] - a[i];
      a[i] = a[i-1];
    }
  }

  cout << ops << endl;

  return 0;
}
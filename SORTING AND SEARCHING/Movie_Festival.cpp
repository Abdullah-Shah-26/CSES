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

  vector<pair<ll,ll>> a(n);

  for(int i = 0; i < n; i++){
    cin >> a[i].first >> a[i].second;
  }

  // sorted based on end times
  auto cmp = [&](auto &x, auto &y){
    return x.second < y.second;
  };

  sort(a.begin(), a.end(), cmp);

  // Include safety check if arr is empty
  ll curSt = a[0].first;
  ll curEnd = a[0].second;
  ll cnt = 1; 

  for(int i = 1; i < n; i++){
    ll nextSt = a[i].first;
    ll nextEnd = a[i].second;

    if(curEnd <= nextSt){
      cnt++;
      curSt = nextSt;
      curEnd = nextEnd;
    }
  }

  cout << cnt << endl;

  return 0;
}
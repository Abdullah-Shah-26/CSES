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

  int n,k;
  cin >> n >> k;

  vector<vector<int>> a;

  for(int i = 0; i < n; i++){
    int l,r;
    cin >> l >> r;
    a.push_back({l,r});
  }

  // Sort by end time - gives maximum future flexibility
  auto cmp = [&](auto &a, auto &b){
    return a[1] < b[1];
  };

  sort(a.begin(), a.end(), cmp); // O(NLogN)
  
  multiset<int> endTimes;

  int ans = 0;

  // TC = O(N Log K)
  for(auto &v : a){
    int s = v[0];
    int e = v[1];

    auto it = endTimes.upper_bound(s);

    if(it != endTimes.begin()){ // Replacing the larger end time & keeping the smaller end times cause they can serve more future intervals
      it--; 
      endTimes.erase(it);
      endTimes.insert(e);
      ans++;
    }
    else  if(endTimes.size() < k){
      endTimes.insert(e);
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
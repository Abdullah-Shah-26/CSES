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

  int n,x;
  cin >> n >> x;

  vll a(n);

  for(int i = 0; i < n; i++) 
    cin >> a[i];
  
  unordered_map<int, pair<int,int>> m;
  
  for(int i = 0; i < n; i++){
    
    for(int j = i + 1; j < n; j++){
      if(m.count(x - a[i] - a[j])){
        cout << i + 1 << " " << j + 1 << " " << m[x-a[i]-a[j]].first + 1  << " " << m[x-a[i]-a[j]].second + 1 << endl;
        return 0;
      }
    }

    for(int j = 0; j < i; j++){
      m[a[i] + a[j]] = {i,j};
    }
  }

  cout << "IMPOSSIBLE" << endl;

  return 0;
}
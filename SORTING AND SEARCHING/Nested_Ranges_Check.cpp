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

  vector<vector<int>> a;

  for(int i = 0; i < n; i++){
    int l,r;
    cin >> l >> r;

    a.push_back({l, r, i});
  }

  // Sort by left - increasing
  // If left same - right decreasing
  sort(a.begin(), a.end(), [](auto &x, auto &y){
    if(x[0] == y[0]) 
      return x[1] > y[1];
    
    return x[0] < y[0];
  });

  vi contains(n);
  vi contained(n);

  // Contained
  int maxR = 0;
  for(int i = 0; i < n; i++){

    int r = a[i][1];
    int idx = a[i][2];

    if(r <= maxR)
      contained[idx] = 1;

    maxR = max(maxR, r);
  }

  // Contains
  int minR = INT_MAX;
  for(int i = n-1; i >= 0; i--){

    int r = a[i][1];
    int idx = a[i][2];

    if(r >= minR)
      contains[idx] = 1;

    minR = min(minR, r);
  }

  for(int x : contains)
    cout << x << " ";
  cout << endl;

  for(int x : contained)
    cout << x << ' ';

  return 0;
}
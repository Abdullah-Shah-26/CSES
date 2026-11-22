#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// Sliding Window Min

int main() {
  fastio();

  int n,a,b;
  cin >> n >> a >> b;

  vll arr(n);
  for(int i = 0; i < n; i++) 
    cin >> arr[i];
  
  vll pref(n + 1);
  // 1.. based prefix sum
  // pref[r + 1] - pref[l] = sum[l......r]

  for(int i = 1; i <= n; i++){
    pref[i] = pref[i-1] + arr[i-1];
  }

  ll ans = LLONG_MIN;

  // Deque stores indices of prefix sums
  deque<int> dq;

  // a <= (r - l + 1) <= b
  // a-1 <= (r - l) <= b-1
  // a-1-r <= -l <= b-1-r
  // r+1-a >= l >= r+1-b
  // r-b+1 <= l <= r-a+1

  for(int r = 0; r < n; r++){

    int newL = r-a+1;

    if(newL >= 0){
      
      // Maintain monotonic inc deque
      while(!dq.empty() && pref[dq.back()] >= pref[newL])
        dq.pop_back();

      dq.push_back(newL);
    }

    // Remove out of window elements
    while(!dq.empty() && dq.front() < r-b+1)
      dq.pop_front();

    if(!dq.empty()){
      ans = max(ans, pref[r+1] - pref[dq.front()]);
    }
  }

  cout << ans << endl;

  return 0;
}
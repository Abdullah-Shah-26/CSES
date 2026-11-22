#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}


ll n, k;
vll a;

int atmost(int k){
  if(k <= 0) return 0;

  ll cnt = 0;
  ll sum = 0;
  int l = 0;
  

  for(int r = 0; r < n; r++){
    sum += a[r];

    while(sum > k){
      sum -= a[l];
      l++;
    }

    cnt += (r - l + 1);
  }

  return cnt ;
}

int main()
{
  fastio();

  cin >> n >> k;

  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  /* 
  for (int i = 0; i < n; i++)
  {
    ll sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += a[j];

      if (sum == x)
        cnt++;
    }
  } 
  */

  cout << atmost(k) - atmost(k-1) << endl;
    
  return 0;
}
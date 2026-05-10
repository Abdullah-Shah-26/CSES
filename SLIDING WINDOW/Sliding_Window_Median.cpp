// CSES Problem
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
 
void rebalance(multiset<ll> &left, multiset<ll> &right)
{
 
  while(left.size() > right.size() + 1)
  {
    auto it = prev(left.end());
    right.insert(*it);
    left.erase(it);
  }
 
  while (left.size() < right.size())
  {
    auto it = right.begin();
    left.insert(*it);
    right.erase(it);
  }
}
 
void solve()
{
  ll n, k;
  cin >> n >> k;
 
  vector<int> nums(n + 1, 0);
 
  for (int i = 1; i <= n; i++)
    cin >> nums[i];
 
  multiset<ll> left, right;
 
  //! Handle First Window
  for (int i = 1; i <= k; i++)
  {
    ll x = nums[i];
 
    if (left.empty() || x <= *left.rbegin())
      left.insert(x);
    else
      right.insert(x);
 
    rebalance(left, right);
  }
 
  cout << *left.rbegin() << " ";
 
  //! Handle Remaining Windows
  for (int i = k + 1; i <= n; i++)
  {
    int next = nums[i];
    int prev = nums[i - k];
 
    if (left.empty() || next <= *left.rbegin())
      left.insert(next);
    else
      right.insert(next);
 
   //! Deletion
  auto it = left.find(prev);
  if(it != left.end()) left.erase(it);
  else{
    auto it2 = right.find(prev); 
    
    if(it2 != right.end())
      right.erase(it2);
  }
 
    rebalance(left, right);
    cout << *left.rbegin() << " ";
  }
  return;
}
 
int main(){
  fastio();
  solve();
}
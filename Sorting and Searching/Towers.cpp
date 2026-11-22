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

int main()
{
  fastio();

  ll n;
  cin >> n;

  multiset<ll> towerHeads;

  for (int i = 0; i < n; i++)
  {
    ll h;
    cin >> h;

    auto it = towerHeads.upper_bound(h);

    if (it == towerHeads.end())
    {
      // No towers present
      towerHeads.insert(h);
    }
    else
    {
      towerHeads.erase(it);
      towerHeads.insert(h); // Replace the head since we are placing h
    }
  }

  cout << (int)towerHeads.size() << endl;

  return 0;
}
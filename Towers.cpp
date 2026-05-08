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

  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll towers = 0;
  ll maxi = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (a[i] > maxi)
    {
      maxi = a[i];
      towers++;
    }
  }

  cout << towers << endl;

  return 0;
}
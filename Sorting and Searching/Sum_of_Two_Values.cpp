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

  ll n, x;
  cin >> n >> x;

  map<ll, ll> m;
  vll a(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  // a + b = x;
  // b = x - a

  for (int i = 0; i < n; i++)
  {
    if (m.count(x - a[i]))
    {
      int pos1 = m[x - a[i]];
      int pos2 = i;

      if (pos1 != pos2)
      {
        cout << pos1 + 1 << " " << pos2 + 1 << endl;
        return 0;
      }
    }

    m[a[i]] = i;
  }

  cout << "IMPOSSIBLE" << endl;

  return 0;
}
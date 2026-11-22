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

  ll n, k;
  cin >> n >> k;

  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  map<int, int> m;
  ll distinct = 0;

  ll cnt = 0;

  int l = 0;
  for (int r = 0; r < n; r++)
  {
    m[a[r]]++;

    if (m[a[r]] == 1)
      distinct++;

    while (distinct > k)
    {
      m[a[l]]--;

      if (m[a[l]] == 0)
      {
        distinct--;
        m.erase(a[l]);
      }

      l++;
    }

    cnt += (r - l + 1);
  }

  cout << cnt << endl;

  return 0;
}
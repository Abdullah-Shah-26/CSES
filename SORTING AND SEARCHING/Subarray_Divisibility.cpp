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

ll n;
vll a;

int main()
{
  fastio();

  cin >> n;
  a.resize(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  vll freq(n, 0);

  ll pref = 0;
  ll ans = 0;

  freq[0] = 1;

  for (int i = 0; i < n; i++)
  {
    pref += a[i];

    ll rem = ((pref % n) + n) % n;

    ans += freq[rem];

    freq[rem]++;
  }

  cout << ans << endl;

  return 0;
}
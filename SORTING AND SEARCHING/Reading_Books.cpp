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

  vll t(n);

  for (int i = 0; i < n; i++)
    cin >> t[i];

  ll minTotalTime = accumulate(t.begin(), t.end(), 0LL);
  ll maxTime = *max_element(t.begin(), t.end());

  cout << max(minTotalTime, 2 * maxTime) << endl;

  return 0;
}
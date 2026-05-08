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

  map<ll, ll> m;

  for (int i = 0; i < n; i++)
  {
    ll st, end;
    cin >> st >> end;

    m[st]++;
    m[end + 1]--;
  }

  ll overLap = 0;
  ll maxOverLap = 0;
  for (auto &it : m)
  {
    overLap += it.second;
    maxOverLap = max(overLap, maxOverLap);
  }

  cout << maxOverLap << endl;

  return 0;
}
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

  sort(a.begin(), a.end());

  ll sum = 1;
  for (auto &c : a)
  {
    if (c > sum)
      break;

    sum += c;
  }

  cout << sum << endl;

  return 0;
}
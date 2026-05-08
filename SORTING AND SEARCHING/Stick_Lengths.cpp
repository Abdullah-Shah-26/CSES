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

  sort(begin(a), end(a));

  // n = odd -> median = middle element
  // n = even -> median = Avg of middle elements

  ll median = 0;

  if (n & 1)
  {
    median = a[n / 2];
  }
  else
  {
    median = (a[(n - 1) / 2] + a[n / 2]) / 2;
  }

  ll ops = 0;
  for (auto &x : a)
  {
    ops += abs(median - x);
  }

  cout << ops << endl;

  return 0;
}
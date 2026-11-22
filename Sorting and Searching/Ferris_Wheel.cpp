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

  int n;
  cin >> n;

  ll x;
  cin >> x;

  vll a(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(begin(a), end(a));

  ll gondolas = 0;
  int i = 0, j = n - 1;

  // Pair (lightest, heaviest)

  while (i <= j)
  {
    if (a[i] + a[j] <= x)
    {
      i++;
    }

    j--;
    gondolas++;
  }

  cout << gondolas << endl;

  return 0;
}
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

  vector<pair<ll,ll>> a(n);

  for (int i = 0; i < n; i++)
    cin >> a[i].first >> a[i].second;

  // Shortest Job First

  sort(a.begin(), a.end());

  ll profit = 0;
  ll finishTime = 0;

  for (int i = 0; i < n; i++)
  {
    auto [duration, deadline] = a[i];

    finishTime += duration;
    profit += (deadline - finishTime);
  }

  cout << profit << endl;

  return 0;
}
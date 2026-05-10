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

  int l = 0;
  ll cnt = 0;
  set<ll> st;

  for (int r = 0; r < n; r++)
  {
    while (st.count(a[r]))
    {
      st.erase(a[l]);
      l++;
    }

    st.insert(a[r]);
    cnt += (r - l + 1);
  }

  cout << cnt << endl;

  return 0;
}
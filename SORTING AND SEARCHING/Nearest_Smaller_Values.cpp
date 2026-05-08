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

  stack<ll> st;
  vll ans(n, 0);

  for (int i = 0; i < n; i++)
  {

    while (!st.empty() && a[st.top()] >= a[i])
      st.pop();

    ans[i] = st.empty() ? 0 : st.top() + 1;

    st.push(i);
  }

  for (auto &x : ans)
    cout << x << " ";

  return 0;
}
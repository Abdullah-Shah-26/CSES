#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main()
{
  fastio();

  int n;
  cin >> n;

  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  set<int> st;

  int ans = 0;
  int l = 0;

  for (int r = 0; r < n; r++)
  {
    while (st.count(a[r]))
    {
      st.erase(a[l]);
      l++;
    }

    st.insert(a[r]);
    ans = max(ans, r - l + 1);
  }

  cout << ans << endl;

  return 0;
}
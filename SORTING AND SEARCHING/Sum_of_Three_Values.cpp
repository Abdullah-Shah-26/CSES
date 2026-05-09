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

// Sorting + 2 Pointer

int main()
{
  fastio();

  int n, x;
  cin >> n >> x;

  vector<pair<ll, int>> a(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i].first;
    a[i].second = i + 1;
  }

  sort(a.begin(), a.end());

  for (int i = 0; i < n; i++){
    ll newT = x - a[i].first;

    for(int j = i + 1, k = n-1; j < k; j++) {

      while (a[j].first + a[k].first > newT)
        k--;

      if (j < k && a[j].first + a[k].first == newT) {
        cout << a[i].second << " " << a[j].second << " " << a[k].second;
        return 0;
      }
    }
  }

  cout << "IMPOSSIBLE" << endl;

  return 0;
}
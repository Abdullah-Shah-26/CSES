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

  int x, n;
  cin >> x >> n;

  set<int> positions;
  multiset<int> lengths;

  positions.insert(0);
  positions.insert(x);

  lengths.insert(x - 0);

  for (int i = 0; i < n; i++)
  {
    int added;
    cin >> added;
    positions.insert(added);

    auto it = positions.find(added);
    int prevVal = *prev(it);
    int nextVal = *next(it);
    lengths.erase(lengths.find(nextVal - prevVal)); // since old segment no longer exist, its now divided
    lengths.insert(added - prevVal); // prevVal ------ added ------ nextVal
    lengths.insert(nextVal - added);

    cout << *lengths.rbegin() << " ";
  }

  return 0;
}

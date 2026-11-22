#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main() {
  fastio();

  int n, m;
  cin >> n >> m;

  vi a(n + 1);
  vi pos(n + 1);

  for(int i = 1; i <= n; i++){
    cin >> a[i];
    pos[a[i]] = i;
  }

  int rounds = 1;

  for(int i = 1; i < n; i++){
    if(pos[i] > pos[i+1]){
      rounds++;
    }
  }

  auto bad = [&](int i){
    if(i < 1 || i >= n) return false;
    return pos[i] > pos[i+1];
  };

  while(m--){
    int p1, p2;
    cin >> p1 >> p2;

    int x = a[p1];
    int y = a[p2];

    set<int> s;

    s.insert(x - 1);
    s.insert(x);

    s.insert(y - 1);
    s.insert(y);

    for(auto i : s)
      rounds -= bad(i);

    swap(a[p1], a[p2]);
    swap(pos[x], pos[y]);

    for(auto i : s)
      rounds += bad(i);

    cout << rounds << endl;
  }

  return 0;
}
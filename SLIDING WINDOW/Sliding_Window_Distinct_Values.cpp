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

  int n,k;
  cin >> n >> k;

  vi a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];

  map<int,int> m;
  for(int i = 0; i < k; i++){
    m[a[i]]++;
  }

  cout << m.size() << " ";

  for(int i = k; i < n; i++){
    int l = a[i-k];
    int r = a[i];

    m[l]--;
    if(m[l] == 0)
      m.erase(l);

    m[r]++;

    cout << (int)m.size() << " ";
  }

  return 0;
}
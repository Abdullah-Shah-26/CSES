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

  int n,m;
  cin >> n >> m;

  vi tickets(n);
  vi customers(m);

  set<pair<int,int>> st;

  for(int i = 0; i < n; i++) {
    cin >> tickets[i];
    st.insert({tickets[i], i});
  }

  for(int i = 0; i < m; i++) {
    cin >> customers[i];
  }

  for(int i = 0; i < m; i++){
    auto it = st.lower_bound({customers[i] + 1, 0});

    if(it == st.begin()){
      cout << -1 << endl;
    }
    else{
      it--;
      cout << (*it).first << endl;
      st.erase(it);
    }
  }

  return 0;
}
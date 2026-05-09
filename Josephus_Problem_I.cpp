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

  int n;
  cin >> n;

  vi a;

  for(int i = 1; i <= n; i++)
    a.push_back(i);

  int st = 1;

  while(!a.empty()){

    vi next;

    for(int i = 0; i < a.size(); i++){

      if(i % 2 == st){
        cout << a[i] << " ";
      }
      else{
        next.push_back(a[i]);
      }

    }

    // Odd size - parity flip
    if(a.size() % 2 == 1){
      st ^= 1;
    }

    a = next;
  }


  return 0;
}
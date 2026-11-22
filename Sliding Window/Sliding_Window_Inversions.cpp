#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Fenwick{
  public:
  int n;
  vector<int> bit;

  Fenwick(int n){
    this->n = n;
    bit.assign(n + 1, 0);
  }

  void update(int idx, int val){
    while(idx <= n){
      bit[idx] += val;
      idx += idx & -idx;
    }
  }

  int query(int idx){
    int sum = 0;
    while(idx > 0){
      sum += bit[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }
};

int main() {
  fastio();

  int n,k;
  cin >> n >> k;

  vi a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];

  vi vals = a;

  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  for(int &x : a){
    x = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
  }

  int m = vals.size();

  Fenwick ft(m);

  ll inv = 0;

  // 1st window
  for(int i = 0; i < k; i++){
    int x = a[i];

    inv += i - ft.query(x);

    ft.update(x, 1);
  }

  cout << inv <<  " ";

  for(int l = 0, r = k; r < n; r++,l++){

    inv -= ft.query(a[l]-1); // removing contributing of l
    ft.update(a[l],-1);


    // add r
    inv += (k-1) - ft.query(a[r]); // Elements to the left but strictly > a[r]
    ft.update(a[r], 1);

    cout << inv << " ";
  }

  return 0;
}
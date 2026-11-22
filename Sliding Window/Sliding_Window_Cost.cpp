#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// For minimizing sum |a[i] - x|, any median works.
// We use the lower median because it is easy to maintain dynamically.

//For minimization of sum (a[i] - x) ^ 2, optimal x = mean

// leftMaxHeap, rightMinHeap
multiset<ll> L, R;

ll ls = 0; // leftSum
ll rs = 0; // rightSum

void rebalance(){
  
  while(L.size() > R.size() + 1){
    auto it = prev(L.end());

    ll x = *it;

    L.erase(it);
    ls -= x;

    R.insert(x);
    rs += x;
  }

  while(L.size() < R.size()){
    auto it = R.begin();

    ll x = *it; 

    R.erase(it);
    rs -= x;

    L.insert(x);
    ls += x;
  }
}

void add(ll x){

  if(L.empty() || x <= *L.rbegin()){
    L.insert(x);
    ls += x;
  }
  else{
    R.insert(x);
    rs += x;
  }

  rebalance();
}

void remove(ll x){

  if(L.find(x) != L.end()){
    L.erase(L.find(x));
    ls -= x;
  }
  else if(R.find(x) != R.end()){
    R.erase(R.find(x));
    rs -= x;
  }

  rebalance();
}

ll getCost(){
  ll median = *prev(L.end());

  ll costL = median * L.size() - ls;
  ll costR = rs - median * R.size();
  
  return costL + costR;
}

int main() {
  fastio();

  int n,k;
  cin >> n >> k;

  vi a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];


  for(int i = 0; i < k; i++){
    int x = a[i];
    add(x);
  }

  cout << getCost() << " ";

  for(int i = k; i < n; i++){
    ll l = a[i-k];
    ll r = a[i];

    remove(l);
    add(r);

    cout << getCost() << " ";
  }

  return 0;
}
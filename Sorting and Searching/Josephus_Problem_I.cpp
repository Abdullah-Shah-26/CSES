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

  vi children(n);

  for(int i = 0; i < n; i++)
    children[i] = i + 1;

  while(children.size() > 1){

    vi survivors;

    for(int i = 0; i < children.size(); i++){
      
      // First remove guys at even positions - ie odd indices
      if(i % 2 == 1){
        cout << children[i] << " ";
      }
      else{
        survivors.push_back(children[i]);
      }
    }

    if(children.size() % 2 == 0)
      children = survivors;
    else{
      int starter = survivors.back();
      survivors.pop_back();
      children.clear();
      children.push_back(starter);

      for(int z : survivors){
        children.push_back(z);
      }
    }
  }

  cout << children[0] << endl;
 
  return 0;
}
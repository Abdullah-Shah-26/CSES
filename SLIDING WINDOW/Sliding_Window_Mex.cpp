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

  int n, k;
  cin >> n >> k;

  vi a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  set<int> st; // Contains missing

  for(int x = 0; x <= k; x++){
    st.insert(x);
  }
  
  vi freq(k + 1);

  // 1st Window
  for(int i = 0; i < k; i++){
    int x = a[i];

    if(x <= k){
      if(freq[x] == 0){
        st.erase(x);
      }
      freq[x]++;
    }
  }

  // 1st Mex
  cout << *st.begin() << " ";

  for(int i = k; i < n; i++){
    int out = a[i-k];
    int in = a[i];

    if(out <= k){
      freq[out]--;

      if(freq[out] == 0){
        st.insert(out);
      }
    }

    if(in <= k){
      if(freq[in] == 0){
        st.erase(in);
      }
      freq[in]++;
    }

    cout << *st.begin() << " ";
  }

  return 0;
}
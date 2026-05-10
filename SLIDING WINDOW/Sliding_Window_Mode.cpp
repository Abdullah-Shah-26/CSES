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

int main(){
  fastio();

  int n, k;
  cin >> n >> k;

  vi a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  // We want (Largest freq, Smallest value)

  unordered_map<int,int> freq;
  set<pair<int,int>> st; // {-freq, value} so that we can access element with largest freq using st.begin()

  // 1st Window
  for(int i = 0; i < k; i++){
    // Erase Old Enteries 
    if(freq[a[i]] >  0){
      st.erase({-freq[a[i]], a[i]});
    }
    
    // Add New Entry
    freq[a[i]]++;
    st.insert({-freq[a[i]], a[i]});
  }

  cout << st.begin()->second << " ";

  for(int i = k; i < n; i++){
    int l = a[i-k];
    int r = a[i];

    // remove left guy
    st.erase({-freq[l], l});
    freq[l]--; // decrease its freq

    // If its still present in current window - add its new entry
    if(freq[l] > 0){ 
      st.insert({-freq[l], l});
    }

    // remove stale entry of right guy
    if(freq[r] > 0){
      st.erase({-freq[r], r});
    }

    // Add right guy
    freq[r]++;
    st.insert({-freq[r], r});

    cout << st.begin()->second << " ";
  }

  return 0;
}
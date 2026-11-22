#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// TODO : 

vi a;
int n,k;

vi NSEE(){
  vi nsee(n, n);
  stack<int> st;

  for(int i = n-1; i >= 0; i--){
    while(!st.empty() && a[st.top()] > a[i])
      st.pop();

    if(!st.empty())
      nsee[i] = st.top();

    st.push(i);
  }
  return nsee;
}

vi PSE(){
  vi pse(n, -1);
  stack<int> st;

  for(int i = 0; i < n; i++){
    while(!st.empty() && a[st.top()] >= a[i])
      st.pop();

    if(!st.empty())
      pse[i] = st.top();

    st.push(i);
  }
  return pse;
}

int main() {
  fastio();

  cin >> n >> k;

  a.resize(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];

  vi nsee = NSEE();
  vi pse = PSE();

  return 0;
}
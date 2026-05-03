#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;
const int INF = 1e9;
inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// TC = O(N Log N) |  SC = O(N) 

// Gives me the max route len (dp) among all reachable moutains 
// Tree[node] = max dp value in range [l.......r]
struct SegTree {
    int n;
    vector<int> seg;

    SegTree(int sz) {
        n = sz;
        seg.assign(4 * n, 0);
    }

    void update(int i, int l, int r, int pos, int val) {
        if (l == r) {
            seg[i] = max(seg[i], val);
            return;
        }

        int mid = (l + r) >> 1;

        if (pos <= mid)
            update(2*i+1, l, mid, pos, val);
        else
            update(2*i+2, mid+1, r, pos, val);

        seg[i] = max(seg[2*i+1], seg[2*i+2]);
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;

        if (ql <= l && r <= qr) return seg[i];

        int mid = (l + r) >> 1;

        return max(
            query(2*i+1, l, mid, ql, qr),
            query(2*i+2, mid+1, r, ql, qr)
        );
    }

    void update(int pos, int val) {
        update(0, 0, n-1, pos, val);
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(0, 0, n-1, l, r);
    }
};

int main() {
  fastio();

  ll n;
  cin >> n;

  vi ht(n);

  for(int i = 0; i < n; i++) 
    cin >> ht[i];

  vi PGE(n,-1), NGE(n,n);
  stack<int> st;
  
  // Previous Greater or Equal Element
  for(int i = 0; i < n; i++){

    while(!st.empty() && ht[st.top()] < ht[i])
      st.pop();

    PGE[i] = st.empty() ? -1 : st.top();

    st.push(i);
  }

  while(!st.empty()) st.pop();

  // Next Greater or Equal Element
  for(int i = n-1; i >= 0; i--){

    while(!st.empty() && ht[st.top()] < ht[i])
      st.pop();

    NGE[i] = st.empty() ? n : st.top();

    st.push(i);
  }

  vector<pair<int,int>> order; // dp[i] depends on smaller mountains so process smaller ht's first

  for(int i = 0; i < n; i++){ 
    order.push_back({ht[i], i});  
  }

  sort(order.begin(), order.end());

  // dp[i] = max best route starting at index = i 
  vi dp(n, 1);

  SegTree seg(n);

  int pos = 0;

  while(pos < n){
    int end = pos;

    // Same height group  : [pos......end-1] -> Cause same ht cannot glide on each other
    while(end < n && order[pos].first == order[end].first)
      end++;

    // Compute cur Ht batch, update later, so equal ht's dont interact
    for(int k = pos; k < end; k++){
      int idx = order[k].second;

      int bestLeft = seg.query(PGE[idx] + 1, idx - 1); // max route len among all reachable mountains on left
      int bestRight = seg.query(idx + 1, NGE[idx] - 1); // max route len among all reachable mountains on right

      dp[idx] = 1 + max(bestLeft, bestRight); // max no of mountains visited from index = idx 
    }

    // Update segTree with recently computed dp values
    // At original idx, store best Len of route starting there 
  
    for(int k = pos; k < end; k++){
      int idx = order[k].second;
      seg.update(idx, dp[idx]);
    }
    
    pos = end; // move to next grp
  }


  cout << *max_element(begin(dp), end(dp));

  return 0;
}
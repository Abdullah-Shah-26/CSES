#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// Functional Graph
int n;
vi nxt;
vi state; // 0 - unvis, 1 - instack, 2 - done
vi depth;
vi ans;

void dfs(int u){
  state[u] = 1;

  int v = nxt[u];

  if(state[v] == 0){
    depth[v] = depth[u] + 1;
    dfs(v);
  }
  else if(state[v] == 1){ // Cycle Detected
    int cycleLen = depth[u] - depth[v] + 1;
    int cur = v;

    // assign ans to cycleNodes
    do{
      ans[cur] = cycleLen;
      cur = nxt[cur];
    }while(cur != v);
  }

  // If curNode is still not assigned, means it was outside of cycle
  if(ans[u] == 0){
    ans[u] = ans[v] + 1;
  }

  state[u] = 2;
}

int main() {
  fastio();

  cin >> n;

  nxt.resize(n+1);
  state.resize(n+1);
  depth.resize(n+1);
  ans.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> nxt[i];

  for(int i = 1; i <= n; i++){
    if(state[i] == 0){
      depth[i] = 0;
      dfs(i);
    }
  }

  for(int i = 1; i <= n; i++){
    cout << ans[i] << " ";
  }

  return 0;
}
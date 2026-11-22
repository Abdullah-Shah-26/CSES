#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// Maximum bipatite matching

int n,m,k;

// adj[boy] = girls this boy can dance with
vector<vi> adj; 

// matchGirl[g] = which boy currently matched with girl g
vi matchGirl;

// visited[g] = already tried this girl in current dfs
vi vis;

bool dfs(int boy){
  // Trying every girl this boy likes
  for(int girl : adj[boy]){
    if(vis[girl]) continue;
    
    vis[girl] = 1; 

    // Case 1 : Girl is free
    if(matchGirl[girl] == -1){
      matchGirl[girl] = boy;
      return true;
    }

    // Case 2 : Girl already taken, Try reallocating to cur boy
    int otherBoy = matchGirl[girl];

    if(dfs(otherBoy)){
      matchGirl[girl] = boy;
      return true;
    }
  }

  return false;
}

int main() {
  fastio();
  cin >> n >> m >> k;

  adj.resize(n + 1);

  for(int i = 0; i < k; i++){
    int boy, girl;
    cin >> boy >> girl;
    adj[boy].push_back(girl);
  }

  matchGirl.assign(m + 1, -1);
  int matches = 0;

  // Try matching every boy
  for(int boy = 1; boy <= n; boy++){
    vis.assign(m + 1, 0);
    if(dfs(boy)){
      matches++;
    }
  }

  cout << matches << endl;

  // Recover ans
  for(int girl = 1; girl <= m; girl++){
    if(matchGirl[girl] != -1){
      cout << matchGirl[girl] << " " << girl << endl;
    }
  }
  
  return 0;
}
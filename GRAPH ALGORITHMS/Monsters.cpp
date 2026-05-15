#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// order_of_key(k) : No of Elements < k
// *find_by_order(i) : Value at idx i (0 - based)

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvpi = vector<vector<pi>>;

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
static const auto fastio = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// ---------- Macros ----------
#define rv(a) for(auto &x:(a)) cin>>x
#define pv(a) do{ for(const auto &x:(a)) cout<<x<<' '; cout<<'\n'; }while(0)
#define rm(mat) for(auto &r:(mat)) for(auto &x:(r)) cin>>x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define nl do{ cout << '\n'; }while(0)

int n,m;
int row[4] = {-1,1,0,0};
int col[4] = {0,0,-1,1};
char dir[4] = {'U','D','L','R'};

vs grid;
vvi monsterDist;
vvi playerDist;
vvi prevDir;

int stR, stC;
int endR = -1, endC = -1;

// ---------- Solve ---------
void solve(){
  cin >> n >> m;

  grid.resize(n);
  monsterDist.resize(n, vi(m,INF));
  playerDist.resize(n, vi(m,INF));
  prevDir.resize(n, vi(m,-1));

  queue<pi>mq;
  queue<pi>pq; 

  for(int i = 0; i < n; i++){
    cin >> grid[i];
    for(int j = 0; j < m; j++){
      if(grid[i][j] == 'M'){
        mq.push({i,j});
        monsterDist[i][j] = 0; 
      }
      else if(grid[i][j] == 'A'){
        pq.push({i,j});
        playerDist[i][j] = 0;
        stR = i;
        stC = j;
      }
    }
  }

  // Monster - BFS MultiSource
  while(!mq.empty()){
    auto [r,c] = mq.front();
    mq.pop();

    for(int k = 0; k < 4; k++){
      int nr = r + row[k];
      int nc = c + col[k];

      if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#'){
        if(monsterDist[r][c] + 1 < monsterDist[nr][nc]){
          monsterDist[nr][nc] = monsterDist[r][c] + 1;
          mq.push({nr, nc});
        }
      }
    }
  }

  bool possible = false;
  while(!pq.empty()){
    auto [r,c] = pq.front();
    pq.pop();

    if(r == 0 || r == n-1 || c == 0 || c == m-1){
      possible = true;
      endR = r;
      endC = c;
      break;
    }

    for(int k = 0; k < 4; k++){
      int nr = r + row[k];
      int nc = c + col[k];

      if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#'){
        // Player should reach earlier than monster
        if(playerDist[r][c] + 1 < monsterDist[nr][nc] && playerDist[r][c] + 1 < playerDist[nr][nc]){
          playerDist[nr][nc] = 1 + playerDist[r][c];
          prevDir[nr][nc] = k;
          pq.push({nr, nc});
        }
      }
    }
  }

    if(!possible){
      cout << "NO" << endl;
      return;
    }

    cout << "YES" << endl;
    string path = "";

    int curR = endR;
    int curC = endC;

    while(curR != stR || curC != stC){
      int d = prevDir[curR][curC];
      path += dir[d];
      curR -= row[d]; // Go back to parent
      curC -= col[d];
    }

    reverse(all(path));
    cout << path.size() << endl;
    cout << path << endl;
}

// ---------- Main ----------
int main(){
    solve();
    return 0;
}
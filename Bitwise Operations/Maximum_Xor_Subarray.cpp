#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class TrieNode{
  public:
  TrieNode* child[2];

  TrieNode(){
    child[0] = NULL;
    child[1] = NULL;
  }
};

class Trie{
  private: 
  TrieNode* root;

  public:
  Trie(){
    root = new TrieNode();
  }

  void insert(ll num){
    TrieNode* cur = root;

    for(int i = 31; i >= 0; i--){
      int bit = (num >> i) & 1;

      if(cur->child[bit] == NULL){
        cur->child[bit] = new TrieNode();
      }

      cur = cur->child[bit];
    }
  }

  ll getMaxXor(ll num){
    TrieNode* cur = root;
    ll ans = 0;

    for(int i = 31; i >= 0; i--){
      int bit = (num >> i) & 1;

      if(cur->child[!bit] != NULL){
        ans |= (1LL << i);
        cur = cur->child[!bit];
      }
      else{
        cur = cur->child[bit];
      }
    }
    return ans;
  }
};

int main() {
  fastio();

  int n;
  cin >> n;
  
  vll a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  Trie trie;
  ll ans = *max_element(begin(a), end(a));

  // pref[r] ^ pref[l-1]
  ll prefXor = 0;
  trie.insert(0); // Initally inserting 0, as we do in prefix sum's too because some optimal subarr may start from 0

  for(int i = 0; i < n; i++){
    prefXor ^= a[i];

    // Pairing pref[r] with best pref[l-1] to maximize ans 
    ans = max(ans, trie.getMaxXor(prefXor));

    trie.insert(prefXor);
  }
 
  cout << ans << endl;

  return 0;
}
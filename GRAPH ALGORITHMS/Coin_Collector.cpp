#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;

vector<ll> coins;

vector<vector<int>> adj, revAdj;

// for kosaraju
vector<bool> vis;
vector<int> order;
vector<int> comp;

// compressed DAG
vector<vector<int>> dag;

// SCC coin sums
vector<ll> sccCoins;

// DP
vector<ll> dp;

// stores nodes in finishing order
void dfs1(int u) {
    vis[u] = true;

    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }

    order.push_back(u);
}

// assigns SCC id
void dfs2(int u, int id) {
    comp[u] = id;

    for (int v : revAdj[u]) {
        if (comp[v] == -1) {
            dfs2(v, id);
        }
    }
}

// ---------- DAG DP ----------
ll solve(int u) {
    if (dp[u] != -1) {
        return dp[u];
    }

    ll best = 0;

    for (int v : dag[u]) {
        best = max(best, solve(v));
    }

    return dp[u] = sccCoins[u] + best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    coins.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    adj.resize(n + 1);
    revAdj.resize(n + 1);

    vector<pair<int,int>> edges;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        revAdj[b].push_back(a);

        edges.push_back({a, b});
    }

    // ---------- Kosaraju Step 1 ----------
    vis.assign(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }

    // ---------- Kosaraju Step 2 ----------
    comp.assign(n + 1, -1);

    reverse(order.begin(), order.end());

    int sccCount = 0;

    for (int node : order) {
        if (comp[node] == -1) {
            dfs2(node, sccCount);
            sccCount++;
        }
    }

    // ---------- SCC coin sums ----------
    sccCoins.assign(sccCount, 0);

    for (int i = 1; i <= n; i++) {
        sccCoins[comp[i]] += coins[i];
    }

    // ---------- Build compressed DAG ----------
    dag.resize(sccCount);

    for (auto [u, v] : edges) {
        int cu = comp[u];
        int cv = comp[v];

        // only edges between different SCCs
        if (cu != cv) {
            dag[cu].push_back(cv);
        }
    }

    // ---------- DP on DAG ----------
    dp.assign(sccCount, -1);

    ll ans = 0;

    for (int i = 0; i < sccCount; i++) {
        ans = max(ans, solve(i));
    }

    cout << ans << '\n';
}
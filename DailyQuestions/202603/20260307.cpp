//DFS + DP
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const ll INF = 1e18;
const int N =  1e5 + 10;
struct edge{
    int to;
    ll w;
};
int s;
ll W[N];
vector<edge> adj[N];
void dfs(int u, int fa){
    if ((int)adj[u].size() == 1 && u != s) {
        W[u] = INF;
        return ;
    }
    for (auto [v, w] : adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        W[u] += min(w, W[v]);
    }
}
void solve(){
    int  n, m;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++) {
        W[i] = 0;
    }
    dfs(s, 0);
    cout << W[s] << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}

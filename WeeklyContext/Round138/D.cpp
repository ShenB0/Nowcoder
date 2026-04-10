#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
#define lowbit(x) (x) & (-x)
#define vec vector<int>
#define vvec vector<vector<int>>
#define rep(i, a, b) for(int i = (a); i <= (int)(b); ++i)
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double eps = 1e-7;
const int N =  2e5 + 10;
vector<int> adj[N];
void solve(){
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    
    vector<int> color(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> vis(n + 1, false);
    vector<int> son(n + 1, 1);
    auto dfs = [&](auto&& dfs, int u) -> void {
        vis[u] = true;
        for (int v : adj[u]) {
            if (vis[v]) continue;
            if (color[v] != color[u]) continue;
            dfs(dfs, v);
            son[u] += son[v];
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(dfs, i);
        }
    }
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1LL * (son[i] - 1);
    }
//     for (int i = 1; i <= n; i++) {
//         cout << son[i] << " ";
//     }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}

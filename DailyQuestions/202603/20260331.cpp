#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  5e5 + 10;
int w[N];
vector<int> adj[N];
int a, b;
ll cnt = 0;
ll dp[N][4];
// dp[u][0]: 全员在 (a, b) 
// dp[u][1]: 全员 > a
// dp[u][2]: 全员 < b
// dp[u][3]: 无限制 (所有连向子树的链)
// 所有链条可以看作是经过某个最高点(lca)统计某个节点两边子树满足条件的节点，用容斥得出
void dfs(int u, int fa) {
    if (w[u] > a && w[u] < b) dp[u][0] = 1;
    if (w[u] > a) dp[u][1] = 1;
    if (w[u] < b) dp[u][2] = 1;
    dp[u][3] = 1;
    for (auto& v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        ll res = 0;
        res += dp[u][3] * dp[v][3];
        res -= dp[u][1] * dp[v][1];
        res -= dp[u][2] * dp[v][2];
        res += dp[u][0] * dp[v][0];
        cnt += res;
        if (w[u] > a) {
            dp[u][1] += dp[v][1];
            if (w[u] < b) dp[u][0] += dp[v][0];
            else dp[u][0] = 0;
        } else {
            dp[u][1] = 0;
            dp[u][0] = 0;
        }
        if (w[u] < b) {
            dp[u][2] += dp[v][2];
        } else {
            dp[u][2] = 0;
        }
        dp[u][3] += dp[v][3];
    }
}
void solve(){
    int n;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << cnt << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

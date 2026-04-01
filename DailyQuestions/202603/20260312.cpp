//拓扑排序
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  1e5 + 10;
int in[N], out[N], dp[N];
vector<int> adj[N];
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++, out[u]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0 && out[i] > 0) {//把单点去除，单点不算食物链
            dp[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            in[v]--;
            dp[v] += dp[u];
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (out[i] == 0) {
            ans += dp[i];
        }
    }
    cout << ans << "\n";
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

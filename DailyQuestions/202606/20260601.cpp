#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    vector<int> adj[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n + 1, false);
    auto dfs = [&](auto&& dfs, int u) -> bool {
        bool flag = false;
        flag |= (u == n);
        for (auto v : adj[u]) {
            if (vis[v]) continue;
            if (a[v] == 1) continue;
            vis[v] = true;
            flag |= dfs(dfs, v);
        }
        return flag;
    };

    vis[1] = true;
    bool ans = dfs(dfs, 1);
    cout << (ans ? "Yes\n" : "No\n");
}
// 64 位输出请用 printf("%lld")

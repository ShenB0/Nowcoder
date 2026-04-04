//dfs+vis[]+并查集
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    int cur;
    auto dfs = [&](auto&& dfs, int u, int fa) {
        if (vis[u]) return;
        cur++;
        vis[u] = vis[fa];
        for (int v : adj[u]) {
            if (v == fa) continue;
            if (vis[v]) continue;;
            if (a[v] != a[u]) continue;
            dfs(dfs, v, u);
        }
    };
    int mx = 0;
    vector<int> val(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[0]++;
            cur = 0;
            dfs(dfs, i, 0);
            val[vis[0]] = cur;
            mx = max(mx, cur);
        }
    }
    vector<int> p;
    for (int i = 1; i <= n; i++) {
        if (val[vis[i]] == mx) {
            p.push_back(i);
        }
    }
    cout << p.size() << "\n";
    for (auto e : p) {
        cout << e << " ";
    }
    cout << "\n";
}

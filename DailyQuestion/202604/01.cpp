//可以链式前向星+一维滚动数组倒序优化
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const double eps = 1e-7;
const int N =  1e6 + 10;
const ll MOD = 1e9 + 7;
vector<int> adj[N];
void solve(){
    int n, m, t, root;
    cin >> n >> m >> t >> root;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    vector<int> dis(n + 1, INF);
    vector<int> num(5005, 0);
    q.push(root);
    dis[root] = 0;
    int mx = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        mx = max(mx, dis[u]);
        num[dis[u]]++;
        for (int v : adj[u]) {
            if (dis[v] == INF) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    vector<vector<ll>> f(mx + 1, vector<ll>(mx + 1, 0));
    for (int i = 0; i <= mx; i++) {
        f[i][0] = 1;
    }
    for (int i = 1; i <= mx; i++) {
        for (int j = 1; j <= mx; j++) {
            f[i][j] = f[i - 1][j];
            f[i][j] = (f[i][j] + f[i - 1][j - 1] * num[i] % MOD) % MOD;
        }
    }
    while (t--) {
        int k;
        cin >> k;
        if (k > mx) {
            cout << "0\n";
            continue;
        }
        cout << f[mx][k] << "\n";
    } 
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

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
const ll LINF = 1LL << 60;
const double eps = 1e-7;
const int N =  1e5 + 10;
int w[N];
bool vis[N];
vector<int> adj[N];
int dfs(int u){
    vis[u] = true;
    int mx = w[u];
    for (auto& v : adj[u]) {
        if (vis[v]) continue;
        mx = max(mx, dfs(v));
    }
    return mx;
} 
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> q;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            q.push_back(dfs(i));
        }
    }
    sort(q.begin(), q.end());
    ll cur = 0;
    int sz = q.size();
    // for  (auto x : q) {
    //     cout << x << " ";
    // }
    for (int i = 1; i < sz; i++) {
        cur += 1LL * q[i];
    }
    cout << cur << "\n";
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

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
const int N =  2e5 + 10;
struct Edge{
    int v, w;
};
int n, m;
double ans = 0;
ll siz[N];
vector<Edge> adj[N];
void dfs(int u, int d, ll k){
    if (u == n) {
        ans += 1.0 * d / k;
        return ;
    }
    for (auto [v, w]: adj[u]) {
        dfs(v, d + w, k * siz[u]);
    }
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++) {
        siz[i] = adj[i].size();
    }
    dfs(1, 0, 1);
    cout << fixed << setprecision(2) << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

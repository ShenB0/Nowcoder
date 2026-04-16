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
const int N =  1e5 + 10;
const ll MOD = 1e9 + 7;
vector<int> adj[N];
ll f[N][2];
void dfs(int u, int fa) {
    f[u][0] = f[u][1] = 1; 
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        f[u][0] = (f[u][0] * f[v][1]) % MOD;
        f[u][1] = (f[u][1] * (f[v][0] + f[v][1])) % MOD;
    }
}
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << (f[1][0] + f[1][1]) % MOD << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

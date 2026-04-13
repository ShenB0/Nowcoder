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
int ans[N], siz[N];
bool dfs(int u, int fa){
    if (siz[u] == 1) {
        ans[0] = 0;
        return false;
    }
    bool tag = true;
    for (int v : adj[u]) {
        if (v== fa) continue;
        tag &= dfs(v, u);
        ans[u] += ans[v];
    }
    if (!tag) {
        ans[u]++;
        return true;
    } else {
        return false;
    }
}
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        ans[i] = siz[i] = 0;
    }
    adj[1].push_back(0);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        siz[i] = adj[i].size();
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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

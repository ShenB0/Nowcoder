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
const int N = 2e5 + 10;
ll a[N], sz[N], p[N], aim[N];
vector<int> g[N];
int ok[N], son[N], val[N], n;
int tree[N];
void add(int x, int v) { for (; x < N; x += x & -x) tree[x] += v; }
int query(int x) { int s = 0; for (; x > 0; x -= x & -x) s += tree[x]; return s; }
vector<ll> b;
int get(ll x) { return lower_bound(b.begin(), b.end(), x) - b.begin() + 1; }
void dfs1(int u, ll s) {
    p[u] = s;
    sz[u] = a[u];
    for (int v : g[u]) {
        dfs1(v, s + a[u]);
        sz[u] += sz[v];
    }
}
void dfs2(int u) {
    son[u] = ok[u];
    bool flag = (p[u] >= a[u] && sz[u] > 2 * a[u]);
    if (flag) add(get(sz[u] - 2 * a[u]), 1);
    for (int v : g[u]) {
        val[v] = query(get(sz[v]));
        dfs2(v);
        son[u] += son[v];
    }
    if (flag) add(get(sz[u] - 2 * a[u]), -1);
}
void solve() {
    cin >> n;
    b.clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[i].clear();
        val[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int f; cin >> f;
        if (f) g[f].push_back(i);
    }
    dfs1(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] >= a[i] && sz[i] <= 2 * a[i]) {
            ok[i] = 1;
            ans++;
        } else ok[i] = 0;
        b.push_back(sz[i]);
        b.push_back(sz[i] - 2 * a[i]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    dfs2(1);
    int mx = 0;
    for (int i = 2; i <= n; i++) {
        mx = max(mx, val[i] - son[i]);
    }
    cout << ans + mx << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

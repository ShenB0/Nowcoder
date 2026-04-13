//连通块方案数公式：
//设连通块大小为 S，环大小为 C，颜色数 q = 26。
//总方案数 = (环的贡献) * (树枝的贡献)
//总方案数 = [25^C + (-1)^C * 25] * 25^(S - C)
//环上染色方案通用公式：
//设环长为 n，颜色数为 q。
//方案数 = (q - 1)^n + (-1)^n * (q - 1)
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
const ll MOD = 998244353;
vector<int> adj[N];
int in[N], dsu[N], siz[N], cnt[N];
ll pow25[N];
void init(){
    pow25[0] = 1LL;
    for (int i = 1; i < N; i++) pow25[i] = pow25[i - 1] * 25 % MOD;
}
int find(int x){
    if (dsu[x] != x) dsu[x] = find(dsu[x]);
    return dsu[x];
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if (x != y) {
        dsu[x] = y;
    }
}
ll f(ll s, ll c){
    if (c & 1) return (pow25[c] - 25 + MOD) % MOD * pow25[s - c] % MOD;
    else return (pow25[c] + 25) % MOD * pow25[s - c] % MOD;
}
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        dsu[i] = i;
        cnt[i] = siz[i] = in[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        merge(i, v);
        adj[i].push_back(v);
        in[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    vector<int> root; 
    for (int i = 1; i <= n; i++) {
        int fa = find(i);
        if (fa != i) siz[fa]++;
        else root.push_back(i);
        if (in[i] != 0) cnt[fa]++;
    }
    ll ans = 1;
    int cycle = 0;
    for (auto p : root) {
        cycle += ++siz[p];
        ans = ans * f(siz[p], cnt[p]) % MOD;
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int t = 1;
    while (t--) solve();
    return 0;
}

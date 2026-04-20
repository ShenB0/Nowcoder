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
struct Edge{
    int u, v;
};
int dsu[N];
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
void solve(){
    int n, m;
    string s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
    }
    vector<Edge> a, b, c;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int f = (s[u - 1] - 'A') / 2;
        int g = (s[v - 1] - 'A') / 2;
        if (f == 0 && g == 0) {
            a.push_back({u, v});
        } else if (f == 1 && g == 1) {
            b.push_back({u, v});
        } else {
            c.push_back({u, v});
        }
    }
    vector<Edge> ans;
    for (auto [u, v] : a) {
        if (find(u) != find(v)) {
            merge(u, v);
            ans.push_back({u, v});
        }
    }
    for (auto [u, v] : b) {
        if (find(u) != find(v)) {
            merge(u, v);
            ans.push_back({u, v});
        }
    }
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++) {
        int fa = find(i);
        if (s[fa - 1] != s[i - 1]) {
            vis[fa] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[find(i)]) {
            cout << "No\n";
            return ;
        }
    }
    for (auto [u, v] : c) {
        if (find(u) != find(v)) {
            merge(u, v);
            ans.push_back({u, v});
        }
    }
    if ((int)ans.size() != n - 1) {
        cout << "No\n";
        return ;
    }
    cout << "Yes\n";
    for (auto [u, v] : ans) {
        cout << u << " " << v << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

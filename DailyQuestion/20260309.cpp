//并查集
//让合并父节点取大，方便做区间跳跃，也可以用nxt[]维护
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int a[N];
int fa[N];
int siz[N];
int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if (x > y) swap(x, y);
    if (x != y) {
        fa[x] = y;
        siz[y] += siz[x];
        a[y] += a[x];
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fa[i] = i;
        siz[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            for (int i = find(l); i < r; i = find(i)) {
                merge(i, i + 1);
            }
        } else {
            int x;
            cin >> x;
            int par = find(x);
            cout << 1.0 * a[par] / siz[par] << "\n";
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(10);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

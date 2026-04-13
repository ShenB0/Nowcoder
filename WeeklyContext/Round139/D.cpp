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
int dsu[N];
int find(int x){
    if (dsu[x] != x) dsu[x] = find(dsu[x]);
    return dsu[x];
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    dsu[x] = y;
}
void solve(){
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) dsu[i] = i;
    while (q--) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            ans = ans * 26 % MOD;
        }
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

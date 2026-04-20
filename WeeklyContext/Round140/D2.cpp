//exgcd失效了
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
int dsu[N], a[N];
int find(int x){
    if (dsu[x] != x) dsu[x] = find(dsu[x]);
    return dsu[x];
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if (x != y) {
        dsu[y] = x;
    }
}
void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i + x <= n) merge(i, i + x);
        if (i + y <= n) merge(i, i + y);
    }
    for (int i = 1; i <= n; i++) {
        if (find(a[i]) != find(i)) {
            cout << "No\n";
            return ;
        }
    }
    cout << "Yes\n";
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

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const double eps = 1e-7;
const int N =  2e5 + 10;
const int dx[] = {1, 0};
const int dy[] = {0, 1};
struct node{
    int w, t;
};
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<node>> a(n + 1, vector<node>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j].w;
            a[i][j].t = INF;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y, t;
        cin >> x >> y >> t;
        a[x][y].t = t;
    }
    vector<vector<int>> f(n + 1, vector<int>(m + 1, -1));
    f[1][1] = a[1][1].w;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (f[i][j] == -1) continue;
            for (int k = 0; k < 2; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 1 || nx > n || ny < 1 ||ny > m) continue;
                if (nx + ny - 1 > a[nx][ny].t) continue;
                f[nx][ny] = max(f[nx][ny], f[i][j] + a[nx][ny].w);
            }
        }
    }
    int mx = f[1][1];
    for (int i = 1; i <= n; i++) {
        mx = max(mx, *max_element(f[i].begin(), f[i].end()));
    }
    cout << mx << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}

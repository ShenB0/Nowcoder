#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
struct date{
    int mi_x, mi_y, mx_x, mx_y, c;
};
int n, m;
string a[N];
bool vis[N][N];
date dfs(int x, int y){
    vis[x][y] = true;
    int mix = x, miy = y, mxx = x, mxy = y, cnt = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (a[nx][ny] != '.') continue;
        if (vis[nx][ny]) continue;
        auto [a, b, c, d, e] = dfs(nx, ny);
        mix = min(mix, a), miy = min(miy, b);
        mxx = max(mxx, c), mxy = max(mxy, d);
        cnt += e;
    }
    return {mix, miy, mxx, mxy, cnt};
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.' && !vis[i][j]) {
                auto [a, b, c, d, e] = dfs(i, j);
                if ((c - a + 1) * (d - b + 1) == e) {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
}

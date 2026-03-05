//最短路径--BFS，保证每个点只被搜索一次(记忆化处理)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  1e3 + 10;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
char a[N][N];
int d[N][N];
void solve(){
    int n, m;
    cin >> n >> m;
    int bx, by, ex, ey;
    cin >> bx >> by >> ex >> ey;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            d[i][j] = -1;
        }
    }
    if (a[bx][by] == '*') {
        cout << "-1\n";
        return;
    }
    if (a[ex][ey] == '*') {
        cout << "-1\n";
        return;
    }
    queue<pair<int, int>> q;
    q.push({bx, by});
    d[bx][by] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (~d[nx][ny]) continue;
            if (a[nx][ny] != '*') {
                q.push({nx, ny});
                d[nx][ny] = d[x][y] + 1;
            }
            if (nx == ex && ny == ey) {
                cout << d[ex][ey] << "\n";
                return;
            }
        }
    }
    cout << d[ex][ey] << "\n";
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

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e3 + 5;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
char a[N][N];
void solve(){
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '.') cnt++;
        }
    }
    if (cnt == n * m) {
        cout << "Blue\n";
        return ;
    }
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
    set<pair<int, int>> st;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '#' && !vis[i][j]) {
                int cur = 0;
                st.clear();
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                        if (a[nx][ny] == '.') {
                            if (!st.count({nx, ny})) {
                                st.insert({nx, ny});
                                cur++;
                            }
                            continue;
                        }
                        if (a[nx][ny] == '#' && !vis[nx][ny]) {
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                if (cur == cnt) {
                    cout << "Red\n";
                    return ;
                }
            }
        }
    }
    cout << "Draw\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

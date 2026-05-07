#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, k;
string a[N];
bool vis[N][N];
int dfs(int x, int y){
    int res = 1;
    int nx = x + 1;
    if (nx >= n) return res;
    if (a[nx][y] != 'o') return res;
    if (vis[nx][y]) return res;
    vis[nx][y] = true;
    res += dfs(nx, y);
    return res;
}
int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'o' && !vis[i][j]) {
                vis[i][j] = true;
                int tmp = dfs(i, j);
                cnt.push_back(tmp);
            }
        }
    }
    sort(cnt.begin(), cnt.end(), greater<>());
    int sz = cnt.size();
    int ans = 0;
    for (int i = 0; i < sz; i++) {
        int mi = min(k - 1, cnt[i] - 1);
        ans += mi;
        k -= mi + 1;
        if (k == 0) break;
    }
    cout << ans << "\n";
}
// 64 位输出请用 printf("%lld")

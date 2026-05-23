#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

#define debug(x) cout << #x << " = " << x << endl;
#define lowbit(x) (x) & (-x)
#define vec vector<int>
#define vvec vector<vector<int>>
#define rep(i, a, b) for(int i = (a); i <= (int)(b); ++i)

const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double eps = 1e-7;
const int N =  500 + 10;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, -1, 1, 0};
const char s[] = {'D', 'L', 'R', 'U'};

struct state{
    int x, y;
    string path;
};

string a[N];
bool vis[N][N];

void solve(){
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (a[0][0] == '1' || a[n - 1][m - 1] == '1') {
        cout << "-1\n";
        return ;
    }

    queue<state> q;
    q.push({0, 0, ""});
    vis[0][0] = true;
    while (!q.empty()) {
        auto [x, y, p] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (a[nx][ny] == '1') continue;
            if (vis[nx][ny]) continue;
            if (nx == n - 1 && ny == m - 1) {
                cout << p.size() + 1 << "\n" << p + s[i] << "\n";
                return ;
            }
            vis[nx][ny] = true;
            q.push({nx, ny, p + s[i]});
        }
    }

    cout << "-1\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

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
void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cur = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            int c1 = 1, c2 = 1, c3 = 1, c4 = 1;
            if (a[i][j] == a[i][j + 1]) c1 = c4 = 0;
            if (a[i][j + 1] == a[i + 1][j + 1]) c1 = c2 = 0;
            if (a[i + 1][j + 1] == a[i + 1][j]) c2 = c3 = 0;
            if (a[i + 1][j] == a[i][j]) c3 = c4 = 0;
            if (a[i][j] == a[i + 1][j + 1]) c1 = c3 = 0;
            if (a[i + 1][j] == a[i][j + 1]) c2 = c4 = 0;
            cur += c1 + c2 + c3 + c4;
        }
    }
    cout << cur << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

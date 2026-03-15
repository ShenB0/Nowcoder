//滚动数组+二进制优化多重背包
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  3e3 + 5;
struct item{
    ll w, v, s;
}a[N];
ll dp[N];
void solve(){
    int n, m;
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        ll w, v, s;
        cin >> w >> v >> s;
        a[i] = {w, v, s};
    }
    for (int i = 0; i < n; i++) {
        auto [w, v, s] = a[i];
        for (ll k = 1LL; s > 0; k <<= 1) {
            ll num = min(k, s);
            ll W = num * w;
            ll V = num * v;
            for (int j = m; j >= W; j--) {
                dp[j] = max(dp[j], dp[j - W] + V);
            }
            s -= num;
        }
    }
    cout << dp[m] << "\n";
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
// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;
// using ull = unsigned long long;
// using i128 = __int128;
// const int INF = 1 << 30;
// const double eps = 1e-7;
// const int N =  3e3 + 5;
// struct item{
//     ll w, v, s;
// }a[N];
// ll dp[2][N];
// void solve(){
//     ll n, m;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) {
//         ll w, v, s;
//         cin >> w >> v >> s;
//         a[i] = {w, v, s};
//     }
//     memset(dp, 0, sizeof(dp));
//     int cur = 0;
//     int pre = 1;
//     for (int i = 1; i <= n; i++) {
//         auto& [w, v, s] = a[i];
//         for (int j = w; j <= m; j++) {
//             dp[cur][j] = dp[pre][j];
//             for (int k = 0; k <= s && k * w <= j; k++) {
//                 dp[cur][j] = max(dp[pre][j - k * w] + k * v, dp[cur][j]);
//             }
//         }
//         pre = cur;
//         cur = (cur + 1) % 2;
//         memset(dp[cur], 0, sizeof(dp[cur]));
//     }
//     cout << dp[pre][m] << "\n";
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--) solve();
//     return 0;
// }

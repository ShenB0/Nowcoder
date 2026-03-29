#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    int mx = n;
    for (int i = 0; i <= n; i++) {
        int res = n;
        int x = i, y = n - i;
        while (x >= a || y >= b) {
            y += x / a;
            res += x / a;
            x %= a;
            x += y / b;
            res += y / b;
            y %= b;
        }
        mx = max(res, mx);
    }
    cout << mx << "\n";
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

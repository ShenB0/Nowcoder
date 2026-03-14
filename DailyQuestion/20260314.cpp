#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
void solve(){
    ll a, b, x;
    cin >> a >> b >> x;
    if (3 * a <= b) {
        cout << x * a << "\n";
    } else {
        ll ans = x / 3 * b;
        if (x % 3 * a <= b) {
            ans += x % 3 * a;
        } else {
            ans += b;
        }
        cout << ans << "\n";
    }
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

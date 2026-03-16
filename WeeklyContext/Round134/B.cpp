#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
void solve(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    while (b >= y || c >= x) {
        if (b >= y) {
            a += b / y;
            c += b / y;
            b %= y;
        }
        if (c >= x) {
            b += c / x;
            c %= x;
        }
    }
    cout << a << "\n";
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

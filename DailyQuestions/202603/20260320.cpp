#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
void solve() {
    ll n, m;
    cin >> n >> m;
    ll rem = n;
    ll ans = 0;
    for (int i = 31; i >= 0; i--) {
        if (rem >= m * (1LL << i)) {
            rem -= m * (1LL << i);
            ans += (1LL << i);
        } else if (rem > m * ((1LL << i) - 1)){
            ll tmp = rem - m * ((1LL << i) - 1);
            rem -= (tmp + (1LL << i) - 1) / (1LL << i) * (1LL << i);
        }
    }
    cout << ans << "\n";
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

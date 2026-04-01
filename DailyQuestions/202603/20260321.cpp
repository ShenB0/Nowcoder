//最优为[1, n]
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
void solve(){
    ll n, k;
    cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum += x;
    }
    cout << sum * k << "\n";
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

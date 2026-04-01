#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e3 + 5;
const ll MOD = 1e9 + 7;
ll fac[N], inv[N];
ll qpow(ll x, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        b >>= 1;
    }
    return res;
}
void init(){
    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for(int i = N - 2; i >= 1; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}
ll C(ll n, ll k){
    if (k < 0 || k > n) return 0;//非法状态判断
    return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}
void solve(){
    init();
    int x, y;
    cin >> x >> y;
    int n = x + y;
    for (int i = 1; i <= n; i++) {
        ll ans = 0;
        //插板法
        ans = (ans + C(x - 1, (i + 1) / 2 - 1) % MOD * C(y - 1, i / 2 - 1) % MOD) % MOD;//a在头
        ans = (ans + C(x - 1, i / 2 - 1) % MOD * C(y - 1, (i + 1) / 2 - 1) % MOD) % MOD;//b在头
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

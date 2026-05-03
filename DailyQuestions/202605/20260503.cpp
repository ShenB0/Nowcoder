#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 1e6;
ll fac[N + 5], inv[N + 5];
ll qpow(ll x, ll b){
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * x % MOD;
        }
        b >>= 1;
        x = x * x % MOD;
    }
    return res;
}
void init(){
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[N] = qpow(fac[N], MOD - 2);
    for (int i = N - 1; i >= 1; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}
ll C(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || n == 0) return 1;
    return fac[n] * inv[n - k] % MOD * inv[k] % MOD;
}
int main() {
    init();
    int n, x;
    cin >> n >> x;
    int mx = sqrt(x);
    cout << C(mx, n) << "\n";
}
// 64 位输出请用 printf("%lld")

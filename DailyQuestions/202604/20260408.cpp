//先乘完再取逆元更快
#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const int INF = 1 << 30;
const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll inv[N];
void init(){
    inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
}
void solve(){
    int n;
    cin >> n;
    ll p = 1;
    vector<ll> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    for (int i = 0; i < n; i++) {
        p = p * (a[i] - b[i]) % MOD * inv[a[i]] % MOD;
    }
    cout << (1LL - p + MOD) % MOD << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

    

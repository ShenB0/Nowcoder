#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const double eps = 1e-7;
const int N =  2e5 + 10;
ll get(int n, ll val, const vector<ll>& c2, const vector<ll>& c5) {
    if (val <= 0) return 1LL * n * (n + 1) / 2; 
    ll res = 0, cur2 = 0, cur5 = 0;
    int r = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && min(cur2, cur5) < val) {
            cur2 += c2[r];
            cur5 += c5[r];
            r++;
        }
        if (min(cur2, cur5) >= val) {
            res += (ll)(n - r + 1);
        }
        if (r > l) {
            cur2 -= c2[l];
            cur5 -= c5[l];
        } else {
            r = l + 1;
            cur2 = 0; cur5 = 0;
        }
    }
    return res;
}
void solve(){
    int n;
    ll k; 
    if(!(cin >> n >> k)) return;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<ll> c2(n), c5(n);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        ll cnt2 = 0, cnt5 = 0;
        while (x > 0 && x % 2 == 0) { x /= 2; cnt2++; }
        while (x > 0 && x % 5 == 0) { x /= 5; cnt5++; }
        c2[i] = cnt2;
        c5[i] = cnt5;
    }
    ll ans = get(n, k, c2, c5) - get(n, k + 1, c2, c5);
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}

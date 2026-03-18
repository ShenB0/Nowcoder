#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
ll a[N], odd[N], even[N], suf[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            even[i] = -1;
            odd[i] = 0;
        } else {
            odd[i] = -1;
            even[i] = 0;
        }
    }
    suf[n] = odd[n] = even[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + a[i];
        odd[i] = odd[i + 1] + odd[i];
        even[i] = even[i + 1] + even[i];
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] & 1) {
            ans += ((n - i - 1) * a[i] + odd[i + 1] + suf[i + 1]) / 2;
        } else {
            ans += ((n - i - 1) * a[i] + even[i + 1] + suf[i + 1] ) / 2;
        }
    }
//     for (int i = 0; i < n; i++) {
//         cout << odd[i] << " ";
//     }
//     cout << "\n";
//     for (int i = 0; i < n; i++) {
//         cout << even[i] << " ";
//     }
//     cout << "\n";
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
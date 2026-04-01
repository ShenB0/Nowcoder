#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0, k = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            k++;
        } else if (s[i] == 'o') {
            cnt++;
        }
    }
    ll ans = 0;
    for (int i = cnt; i <= cnt + k; i++) {
        vector<ll> f(i + 1, -1); 
        f[0] = 0;
        for (char c : s) {
            for (int j = i; j >= 0; j--) {
                ll res_o = -1, res_v = -1;
                if (c == 'o') {
                    if (j > 0 && f[j - 1] != -1) f[j] = f[j - 1];
                    else f[j] = -1; 
                } 
                else if (c == 'v') {
                    if (f[j] != -1) f[j] += 1LL * j * (i - j);
                } 
                else if (c == '?') {
                    if (f[j] != -1) res_v = f[j] + 1LL * j * (i - j);
                    if (j > 0 && f[j - 1] != -1) res_o = f[j - 1];
                    f[j] = max(res_o, res_v);
                }
            }
        }
        if (f[i] != -1) ans = max(ans, f[i]);
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

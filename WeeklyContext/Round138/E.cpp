#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
#define lowbit(x) (x) & (-x)
#define vec vector<int>
#define vvec vector<vector<int>>
#define rep(i, a, b) for(int i = (a); i <= (int)(b); ++i)
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double eps = 1e-7;
const int N =  2e5 + 10;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll cur = 0;
    vector<ll> f = {-LLINF, -LLINF};
    for (int i = 1; i <= n; i++) {
        int p = abs(a[i]) % 2;
        ll tmp = cur;
        if (f[p] != -LLINF) {
            tmp = max(tmp, f[p] + a[i]); //作为右端点
        }
        f[p] = max(f[p], cur + a[i]);//左端点
        cur = tmp;
    }
    cout << cur << "\n";
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

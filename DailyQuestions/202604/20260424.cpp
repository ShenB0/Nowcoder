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
const ll MOD = 998244353;
void solve(){
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    ll ans = 0;
    ll cur = 1;
    ll tot = 0;
    for (int i = n - 1; i >= 0; i--) {
        tot = (tot + (a[i] - '0') * cur % MOD) % MOD;
        cur = cur * 10 % MOD;
    }
    cur = 1;
    for (int i = m - 1; i >= 0; i--) {
        ans = (ans + ((b[i] - '0') * cur % MOD * n % MOD + tot) % MOD) % MOD;
        cur = cur * 10 % MOD; 
    }
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

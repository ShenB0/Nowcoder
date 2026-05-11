#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

#define debug(x) cout << #x << " = " << x << endl;
#define lowbit(x) (x) & (-x)
#define vec vector<int>
#define vvec vector<vector<int>>
#define rep(i, a, b) for(int i = (a); i <= (int)(b); ++i)

const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double eps = 1e-7;
const int N =  2e5 + 10;
const ll MOD = 1e9 + 7;

map<ll, int> mp;

void divi(ll x){
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                mp[i]++;
                x /= i;
            }
        }
    }
    if (x > 1) mp[x]++;
}

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

void solve(){
    ll x, y;
    cin >> x >> y;
    
    divi(x);
    divi(y);
    
    vector<pair<ll, int>> fac;
    for (auto [v, c] : mp) {
        fac.push_back({v, c});
    }
    int n = fac.size();
    
    ll ans = 0;
    auto dfs = [&](auto&& dfs, int cur, ll x) -> void{
        if (cur == n) {
            ans = (ans + qpow(x % MOD, x % (MOD - 1))) % MOD;//指数取模MOD - 1
            return ;
        }
        
        auto [v, m] = fac[cur];
        ll pre = 1;
        for (int i = 0; i <= m; i++) {
            dfs(dfs, cur + 1, x * pre);
            pre *= v;
        }
    };
    
    dfs(dfs, 0, 1);
    
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

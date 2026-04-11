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
    ll S;
    cin >> n >> S;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        ll x, y, v;
        cin >> x >> y >> v;
        x = llabs(x);
        y = llabs(y);
        a[i] = {x * x + y * y, v};
    }
    sort(a.begin(), a.end());
    ll cur = 0;
    cout << fixed << setprecision(10);
    for (int i = 0; i < n; i++) {
        auto [r, v]  = a[i];
        if (v + cur >= S) {
            cout << sqrt(r) << "\n";
            return ;
        } 
        cur += v;
    }
    cout << "-1\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

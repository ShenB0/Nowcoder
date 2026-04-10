//考虑到只会减小也就是只会影响其自身和左边，所以倒序
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
ll change(ll x) {
    ll res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}
void solve(){
    int n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cur = 0;
    a[n] = LLINF;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            while (a[i] > a[i + 1]) {
                ll x = change(a[i]);
                if (x == a[i]) break;
                else a[i] = x;
                cur++;
            }
            if (a[i] > a[i + 1]) {
                cout << "-1\n";
                return ;
            }
        }
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

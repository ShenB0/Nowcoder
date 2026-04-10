//考虑到每个数最多change3次，所以为O(3 * n)
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
const ll LINF = 1LL << 60;
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
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < a[i - 1]) {
            for (int j = i - 1; j >= 1; j--) {
                if (a[j] > a[j + 1]) {
                    while (a[j] > a[j + 1]) {
                        int x = change(a[j]);
                        if  (x == a[j]) break;
                        else a[j] = x;
                        cur++;
                    }
                } else {
                    break;
                }
                if (a[j] > a[j + 1]) {
                    cout << "-1\n";
                    return ;
                }
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

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

int a[N];

void solve(){
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<int> d(n + 1, 0);
    int res = 0;
    for (int i = 1; i < n; i++) {
        d[i] = ((a[i + 1] - a[i]) % 5 + 5) % 5;
        res += d[i];
    }
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l > 1) {
            res -= d[l - 1];
            d[l - 1] = (d[l - 1] + 1) % 5;
            res += d[l - 1];
        }
        if (r < n) {
            res -= d[r];
            d[r] = ((d[r] - 1) + 5) % 5;
            res += d[r];
        }
            
        cout << res << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

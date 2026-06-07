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

ll a[N], p[N];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n / 2; i++) {
        p[2 * i - 1] = a[i];
        p[2 * i] = a[n - i + 1];
    }

    if (n & 1) {
        p[n] = a[n / 2 + 1];
    }

    p[0] = p[n];

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += llabs(p[i] - p[i - 1]);
    }

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

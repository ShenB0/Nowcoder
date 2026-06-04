//可以用梅森素数2^61 - 1为模数避免冲突
//用pair数组+sort替代map
//如果说 cnt 是利用相同 bkdr 为连续块来统计个数，那么 last 是直接连续块内部对前一个的尾巴进行比对记录。
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
const int N =  1e6 + 10;
const ull P = 131;

ull h[N], p[N];
ll n, m, k;
string s;

void init(){
    p[0] = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + s[i - 1];
    }
}

ull bkdr(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

void solve(){
    cin >> n >> m >> k >> s;

    init();

    map<ull, int> cnt, last;
    for (int i = 1; i <= n - m + 1; i++) {
        ull v = bkdr(i, i + m - 1);

        if (last[v] != 0 && last[v] + m - 1 >= i) continue;

        last[v] = i;
        cnt[v]++;
    }

    int ans = 0;
    for (auto& [v, c] : cnt) {
        if (c == k) ans++;
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

//$O(V \ln V)$
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
const int N =  1e6;

int a[N + 5];

void solve(){
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1LL * a[i] * i;
    }
    for (int i = 2; i <= N; i++) {
        ll tmp = 0;
        for (int j = i; j <= N; j += i) {
            tmp += 1LL * a[j] * j;
        }
        ans = max(ans, tmp * i);
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

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
    string s;
    cin >> s;
    int n = s.size();
    vvec f(n, vec(2, 0));
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        f[i][0] = 0, f[i][1] = 1;
        ll sum = 0;
        for (int j = i + 1; j < n; j++) {
            if (s[j] == s[j - 1]) {
                f[j][0] = f[j - 1][1];
                f[j][1] = f[j - 1][0] + 1;
            } else {
                f[j][0] = f[j - 1][0];
                f[j][1] = f[j - 1][1] + 1;
            }
            sum += min(f[j][0], f[j][1]);
        }
        ans += sum;
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

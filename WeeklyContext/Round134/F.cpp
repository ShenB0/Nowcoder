//中心扩展预处理所有回文串
//外层枚举右端点，内层枚举合法回文左端点，dp1~n做前缀
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  2e3 + 10;
const ll MOD = 998244353;
bool flag[N][N];
ll dp[N],c[N];
void solve(){
    int n;
    string s;
    cin >> n >> s;
    memset(flag, false, sizeof(flag));
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            flag[l][r] = true;
            l--;r++;
        }
        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            flag[l][r] = true;
            l--;r++;
        }
    }
    memset(dp, 0, sizeof(dp));
    memset(c, 0, sizeof(dp));
    c[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (flag[j][i - 1]) {
                ll len = i - j;
                c[i] = (c[j] + c[i]) % MOD;
                dp[i] = (dp [i] + dp[j] + c[j] * len * len) % MOD;
            }
        }
    }
    cout << dp[n] << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

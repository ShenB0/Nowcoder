#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;
ll dp[N][26];

int main() {
    int n;
    string s;
    cin >> n >> s;

    for (int j = 0; j < 26; j++) {
        dp[0][j] = abs(s[0] - ('A' + j));
    }

    for (int i = 1; i < n; i++) {
        ll pre = dp[i - 1][0]; 

        for (int j = 0; j < 26; j++) {
            pre = min(pre, dp[i - 1][j]);
            dp[i][j] = pre + abs(s[i] - ('A' + j));
        }
    }

    ll ans = dp[n - 1][0];
    for (int j = 1; j < 26; j++) {
        ans = min(ans, dp[n - 1][j]);
    }
    cout << ans << "\n";
}
// 64 位输出请用 printf("%lld")

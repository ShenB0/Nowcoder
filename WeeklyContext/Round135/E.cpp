#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
const ll INF = 1LL << 60;
ll a[N], b[N], c[N], dp[N][6];
ll cost(int id, ll v) {
    if (v > 0) return v * b[id];
    else return -v * c[id];
}
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            dp[i][j] = INF;
        }
    }
    for (int j = -2; j <= 2; j++) {
        if (a[1] + j >= 1) {
            dp[1][j + 2] = cost(1, j);
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = -2; j <= 2; j++) {
            if (a[i] + j < 1) continue;
            for (int k = -2; k <= 2; k++) {
                if (a[i] + j != a[i - 1] + k) {
                    dp[i][j + 2] = min(dp[i][j + 2], dp[i - 1][k + 2] + cost(i, j));
                }
            }
        }
    }
    cout << *min_element(dp[n], dp[n] + 5) << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
    

//进一步用vector+记忆清空代替Map减小开销，以及只对n/m的影响进行分块能更进一步
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
int a[N];
int cal(int r, int n, vector<int>& q){
    if (q.empty()) return n / r;
    map<int, int> mp;
    for (auto& p : q) {
        int col = p % r;
        mp[col]++;
    }
    int mi = n / r;
    for (auto& [v, c] : mp) {
        int sum = (n - 1 - v) / r + 1;;
        mi = min(sum - c, mi);
    }
    return mi;
}
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == k) {
            q.push_back(i);
        }
    }
    int ans = cal(m, n, q);
    for (int i = m + 1; i <= n; i++) {
        if (i - m > ans) break;
        int res = (i - m) + cal(i, n, q);
        ans = min(ans, res);
    }
    for (int i = m - 1; i >= 1; i--) {
        if (m - i > ans) break;
        int res = (m - i) + cal(i, n, q);
        ans = min(ans, res);
    }
    cout << ans << "\n";
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

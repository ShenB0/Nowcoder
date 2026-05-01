#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        int it = upper_bound(a.begin(), a.end(), a[i] + k) - a.begin();
        int len = it - i;
        ans = max(ans, 1.0 * len / n);
    }
    cout << ans << "\n";
}
// 64 位输出请用 printf("%lld")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define vec vector<int>
void solve() {
    int n, k;
    cin >> n >> k;
    vec v(n), w(n);
    for (int i = 0; i < n; ++i) cin >> v[i] >> w[i];
    int res = 0;
    for (int j = 30; j >= 0; --j) {
        int cur = res | (1 << j);
        int val = -1;
        bool ok = false;

        for (int i = 0; i < n; ++i) {
            if ((w[i] & cur) == cur) {
                if (!ok) val = v[i], ok = true;
                else val &= v[i];
            }
        }

        if (ok && val <= k) res = cur;
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}

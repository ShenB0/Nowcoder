#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(ll x, ll y, ll z) {
    return (x + y > z) && (x + z > y) && (y + z > x);
}
void solve() {
    vector<ll> a(6);
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool flag = false;
    do {
        if (check(a[0], a[1], a[2]) && check(a[3], a[4], a[5])) {
            flag = true;
            break; 
        }
    } while (next_permutation(a.begin(), a.end()));
    if (flag) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// 64 位输出请用 printf("%lld")

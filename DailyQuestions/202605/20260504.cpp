#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    ll res = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        res += b[i] - a[i];
        sum += abs(b[i] - a[i]);
    }
    if (res == 0) cout << sum / 2 << "\n";
    else cout << "-1\n";
}
// 64 位输出请用 printf("%lld")

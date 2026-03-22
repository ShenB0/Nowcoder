#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cur = 1;
    int mx = 1;
    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i - 1]) <= 1) {
            cur++;
        } else {
            mx = max(cur, mx);
            cur = 1;
        }
    }
    mx = max(mx, cur);
    cout << mx << "\n";
}
// 64 位输出请用 printf("%lld")

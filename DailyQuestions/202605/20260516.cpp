#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        ll l = max(a, c), r = min(b, d);
        ll p = 0;
        if (l <= r) {
            p = r - l + 1;
        }
        if (p == 0) {
            cout << "0/1\n";
            continue;
        }
        ll q = (b - a + 1) * (d - c + 1);
        ll g = __gcd(p, q);
        p /= g, q /= g;
        cout << p << "/" << q << "\n";
    }

}
// 64 位输出请用 printf("%lld")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    ll d = a - b;
    if (d == 0) {
        if (a == 1) cout << "1\n";
        else cout << "0\n";
    } else if (d == 1) {
        cout << "-1\n";
    } else if (__gcd(a, b) != 1){
        cout << "0\n";
    } else {
        vector<ll> c;
        for (ll i = 2; i * i <= d; i++) {
            if (d % i == 0) {
                c.push_back((i - (a % i)) % i);
                while (d % i == 0) {
                    d /= i;
                }
            }
        }
        if (d > 1) {
            c.push_back((d - (a % d)) % d);
        }
        cout << *min_element(c.begin(), c.end()) << "\n";
    }
}
// 64 位输出请用 printf("%lld")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll x){
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (a == 1) {
            if (b == 1) {
                cout << "NO\n";
            } else {
                if (check(b)) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        } else {
            cout << "NO\n";
        }
    }
}
// 64 位输出请用 printf("%lld")

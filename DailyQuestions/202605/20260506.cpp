#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                cout << i << " ";
                n /= i;
            }
        }
    }
    if (n > 1) cout << n << " ";
    cout << "\n";
}
// 64 位输出请用 printf("%lld")

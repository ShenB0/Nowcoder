#include<bits/stdc++.h>

#define lowbit(x) ((x) & (-x))

using namespace std;

using i128 = __int128;

using ll = long long;

const int INF = 1 << 30;

const int N = 2e5 + 5;

void solve(){

    ll nn, mm, ww, qq, MODD;

    cin >> nn >> mm >> ww >> qq >> MODD;

    i128 n = nn, m = mm, w = ww, q = qq, MOD = MODD;

    auto qpow = [&](i128 x, i128 b) -> i128 {

        i128 res = 1;

        while (b) {

            if (b & 1) {

                res = res * x % MOD;

            }

            x = x * x % MOD;

            b >>= 1;

        }

        return res;

    };

    if (q == 0) cout << "0\n";

    else cout << (ll)qpow(n % MOD * m % MOD, w * q) << "\n";

}

int main(){

    ios::sync_with_stdio(0);

    cin.tie(0);

    int t = 1;

    while (t--) {

        solve();

    }

    return 0;

}


    
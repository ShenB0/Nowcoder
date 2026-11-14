#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

#define debug(x) cout << #x << " = " << x << endl;
#define lowbit(x) (x) & (-x)
#define ALL(x) (x).begin(), (x).end()

const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double eps = 1e-7;
const int N = 2e5 + 10;

void init(){
    
}

void solve(){
    ll a, b;
    cin >> a >> b;

    auto lcm = [&](ll a, ll b) -> ll {
        return a / __gcd(a, b) * b;
    };

    cout << __gcd(a, b) << " " << lcm(a, b) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();

    int t = 1;
    while (t--) solve();
    
    return 0;
}

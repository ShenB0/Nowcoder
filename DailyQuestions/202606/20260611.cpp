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
const int N =  2e5 + 10;

void solve(){
    int x, y;
    cin >> x >> y;
    if ((max(x, y) - min(x, y)) % 3 == 0) cout << "awsl\n";
    else cout << "yyds\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}

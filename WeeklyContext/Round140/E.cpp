// - 如果 x 是奇数，我们令 a = x = n^2 - m^2 = (n + m)(n - m)，取 n - m = 1，n + m = x，解得
//   n = (x + 1)/2，m = (x - 1)/2
//   计算出 b, c 即可。
// - 如果 x 是偶数，我们令 b = x = 2mn，取 n = x/2，m = 1，计算 a, c 即可。
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
#define lowbit(x) (x) & (-x)
#define vec vector<int>
#define vvec vector<vector<int>>
#define rep(i, a, b) for(int i = (a); i <= (int)(b); ++i)
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double eps = 1e-7;
const int N =  2e5 + 10;
void solve(){
    ll x;
    cin >> x;
    if (x == 1 || x == 2) {
        cout << "No\n";
        return ;
    }
    ll n, m;
    if (x & 1) n = (x + 1) / 2, m = (x - 1) / 2; 
    else n = x / 2, m = 1;
    cout << "Yes\n";
    cout << n * n - m * m << " " << 2 * n * m << " " << n * n + m * m << "\n";
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

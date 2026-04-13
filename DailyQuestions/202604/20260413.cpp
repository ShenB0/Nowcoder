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
    int n;
    cin >> n;
    ll odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i & 1) {
            odd += x;
        } else {
            even += x;
        }
    }
    if (n == 1) {
        cout << "YES\n";
        return ;
    }
    ll num_o = n / 2 + n % 2;
    ll num_e = n / 2;
    if (odd % num_o == 0 && even % num_e == 0 && odd / num_o == even / num_e) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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

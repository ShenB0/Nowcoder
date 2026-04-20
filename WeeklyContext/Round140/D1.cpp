//a[i] = i + ax + by
//a[i] - i == ax + by;
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(1 + n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        int g = __gcd(x, y);
        if (abs(a[i] - i) % g != 0) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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

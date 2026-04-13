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
    int n, m;
    cin >> n >> m;
    if (n == 1 && m != 1) {
        cout << "01" + string(m - 2, '1') + "\n";
    }
    else if (m == 1 && n != 1) {
        cout << "0\n";
        for (int i = 2; i <= n; i++) cout << "1\n";
    } else {
        cout << "-1\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

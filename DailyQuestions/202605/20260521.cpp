#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

#define debug(x) cout << #x << " = " << x << endl;
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

    if (n == 1 && x != y) {
        cout << "NO\n";
        return ;
    }

    if ((x & y) == y) {
        if (n & 1) {
            cout << "YES\n";
            for (int i = 1; i < n; i++) {
                cout << x << " ";
            }
            cout << y << "\n";
        } else {
            if (x != y) {
                cout << "YES\n";
                for (int i = 1; i < n; i++) {
                    cout << x << " ";
                }
                cout << (x ^ y) << "\n";
            } else {
                int low = x & (-x);
                if (low == x) {
                    cout << "NO\n";
                    return ;
                }
                cout << "YES\n";
                for (int i = 1; i <= n - 2; i++) {
                    cout << x << " ";
                }
                cout << low << " " << (x ^ low) << "\n";
            }
        }
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

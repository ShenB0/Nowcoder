#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
int a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n > 3 || n == 1) {//注意负数，负数整除会自动+1
        cout << "YES\n";
    } else {
        if (is_sorted(a + 1, a + 1 +n)) {
            cout << "YES\n";
        } else {
            if (a[2] != 2) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

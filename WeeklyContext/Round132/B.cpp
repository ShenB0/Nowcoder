#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
const int N = 2e5 + 5;
void solve(){
    int n;
    cin >> n;
    bool flag = false;
    while (n) {
        int x = n % 10;
        if (x == 5 || x == 0) {
            flag = true;
        }
        n /= 10;
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
    
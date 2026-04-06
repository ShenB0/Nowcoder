#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const double eps = 1e-7;
const int N =  2e5 + 10;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int mx = *max_element(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) {
        if (a[i] == mx) {
            if (i > 1 && a[i - 1] != 0) {
                cout << mx << "\n";
                return ;
            } 
            if (i < n && a[i + 1] != 0) {
                cout << mx << "\n";
                return ;
            }
        }
    }
    if (*min_element(a.begin() + 1, a.end()) == 0 && mx == 1) cout << "-1\n";
    else cout << mx - 1 << "\n";
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

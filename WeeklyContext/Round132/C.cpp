#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
const int N = 2e5 + 5;
int a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == 1) {
            ans++;
            a[i - 1] = 0;
            continue;
        }
        if (a[i] == 1) {
            continue;
        }
        if (__gcd(a[i - 1], a[i]) == 1) {
            ans++;
            a[i] = 0;
        }
    }
    if (a[n - 1] == 1) {
        ans++;
    }
    cout << ans << "\n";
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
    
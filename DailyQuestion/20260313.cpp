#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
const int N = 5e5 + 5;
ll a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int i = 1;
    ll pre = 0;
    while (i < n && a[i] + pre < 0) {//只要为负数就不断"利滚利"
        ll dec = 2 * pre + a[i];
        pre = dec;
        i++;
    }
    ll ans = 0;
    while (i <= n) {
        ans += a[i] + pre;
        i++;
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
    

#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
const int N = 2e5 + 5;
int a[N];
int pref[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] ^ a[i];
    }
    ll cnt = 0, ans = 0;
    for (int i = 1; i < n; i++) {
        if (pref[i] == 0) {
            ans += cnt;
        }
        if (pref[i] == pref[n]) {
            cnt++;
        }
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
    

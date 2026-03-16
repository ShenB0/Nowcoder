#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
ll a[N];
void solve(){
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = accumulate(a, a + n, 0LL);
    ll avg = sum / n;
    if (sum > 0 && sum % n != 0) {//负数是向零取整，不需要再加一了
        avg++;
    }
    ll add = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < avg) {
            add += avg - a[i];
        }
    }
    cout << add << "\n";
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

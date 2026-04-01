#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
const int N = 2e5 + 5;
void solve(){
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    cout << (a + b + c - n - d) / 2 << "\n";
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
    

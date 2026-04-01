//线性筛
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  3e7 + 5;
int fac[N], prime[N];
void init(int n){
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if(fac[i] == 0) {
            fac[i] = i;
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && prime[j] <= n / i; j++) {
            fac[i * prime[j]] = prime[j]; 
            if (i % prime[j] == 0) break; 
        }
    }
}
void solve(){
    int n;
    cin >> n;
    init(n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1LL * fac[i];
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}

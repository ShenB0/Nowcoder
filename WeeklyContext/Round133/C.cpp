#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
const int N = 2e5 + 5;
ll get(int x){
    ll res = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                cnt++;
                x /= i;
            }
            if (cnt & 1) {
                res *= i;
            }
        }
    }
    if (x > 1) {
        res *= x;
    }
    return res;
} 
void solve(){
    ll x, l, r;
    cin >> x >> l >> r;
    ll y = get(x);
    ll L = (l + y - 1) / y;
    ll R = r / y;
    L = ceil(sqrt(L));
    R = floor(sqrt(R));
    if (L <= R) {
        cout << y * R * R << "\n";
    } else {
        cout << "-1\n";
    }
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
    

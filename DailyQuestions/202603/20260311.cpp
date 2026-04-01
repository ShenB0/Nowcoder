#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
const ll INF = 1LL << 60;
void solve(){
    int a, b;
    cin >> a >> b;
    if (b < a) swap(a, b);
    int n = sqrt(2 * b);
    if (n & 1) {
        if (n * n / 2 + 1 < b) {
            n++;
        } else if (a == b) {
            n++;
        }
    } else {
        if (n * n / 2 < b) {
            n++;
        }
    }
    cout << n << "\n";
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
    

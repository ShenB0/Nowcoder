#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const int N =  2e5 + 10;
int d[N], pre[N];
void solve(){
    int n;
    cin >> n;
    pre[0] = INF;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        pre[i] = min(pre[i - 1], d[i]);
    }
    int cur = 0;
    for (int i = n; i >= 1; i--) {
        if (pre[i] >= cur) {
            cur++;
        }
    }
    cout << cur << "\n";
    
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

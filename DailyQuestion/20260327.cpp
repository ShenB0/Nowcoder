#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
int a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cur = 1;
    int i = 0;
    for (; i < n; i++) {
        if (a[i] == 1) {
            cur = (cur + 1) % 2;
        } else {
            break;
        }
    }
    if (i == n) {
        if (cur == 1) cout << "Bob\n";
        else cout << "Alice\n";
    } else {
        if (cur == 1) cout << "Alice\n";
        else cout << "Bob\n";
    }
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

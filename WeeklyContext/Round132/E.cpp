#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
int rev(int x){
    int res = 0;
    while (x) {
        res = 10 * res + x % 10;
        x /= 10;
    }
    return res;
}
void solve(){
    int a, b, k;
    cin >> a >> b >> k;
    vector<bool> Hash(1e6 + 5, false);
    queue<pair<int, int>> q;
    q.push({a, 0});
    while (!q.empty()) {
        auto [x, step] = q.front();
        q.pop();
        if (x == b) {
            cout << step << "\n";
            return ;
        }
        if (!Hash[x] && x <= 1e6) {
            if (x % 10 != 0) q.push({rev(x), step + 1});
            q.push({x + k, step + 1});
            Hash[x] = true;
        }
    }
    cout << "-1\n";
    return ;
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
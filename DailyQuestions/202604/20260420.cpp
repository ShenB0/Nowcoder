#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
#define lowbit(x) (x) & (-x)
#define vec vector<int>
#define vvec vector<vector<int>>
#define rep(i, a, b) for(int i = (a); i <= (int)(b); ++i)
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double eps = 1e-7;
const int N =  2e5 + 10;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int cur = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, cur);
        if (s[i] == 'h') {
            if ((i > 0 && s[i - 1] == 'a') || i == 0) {
                cur++;
            } else {
                cur = 1;
            }
        } else if (s[i] == 'a') {
            if ((i > 0 && s[i - 1] == 'h') || i == 0) {
                cur++;
            } else {
                cur = 1;
            }
        } else {
            cur = 0;
        }
    }
    mx = max(mx, cur);
    cout << mx << "\n";

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

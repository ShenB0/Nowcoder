//舍去L[],改用int在线维护，只有当新的mi产生才更新最优L
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
    int n, x;
    cin >> n >> x;
    vector<int> L(n + 1, INF), a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];        
    }
    int cur = 0;
    int l = 1, r = 1;
    while (r <= n) {
        while (r <= n && cur < x) {
            cur += a[r];
            r++;
        }
        while (l <= r && cur >= x) {
            L[l] = r - l;
            cur -= a[l];
            l++;
        }
    }
    int mi = *min_element(L.begin() + 1, L.end());
    for (int i = 1; i <= n; i++) {
        if (L[i] == mi) {
            cout << i << " " << i + L[i] - 1 << "\n";
            break;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

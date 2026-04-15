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
    cin >> n;
    vector<int> a(10, 0);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++; 
    }
    int mx = *max_element(a.begin() + 1, a.end());
    int mi = *min_element(a.begin() + 1, a.end());
    if (mi >= 1 && mx - mi <= 1) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

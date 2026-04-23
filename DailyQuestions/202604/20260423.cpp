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
    scanf("%d", &n);
    int res = 0;
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        res ^= x;
    }
    printf("%d\n", res);
}
int main(){
    int t = 1;
    while (t--) solve();
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

#define debug(x) cout << #x << " = " << x << endl;
#define lowbit(x) (x) & (-x)
#define vec vector<int>
#define vvec vector<vector<int>>
#define rep(i, a, b) for(int i = (a); i <= (int)(b); ++i)

const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double eps = 1e-7;
const int N =  1e6 + 10;

struct node{
    int mx, se;
}a[N];
vector<int> adj[N];

int ans = 0; 

int dfs(int u, int fa){
    int mx = 0; 
    int se = 0; 

    for (auto v : adj[u]) {
        if (v == fa) continue;

        int p = dfs(v, u);
        if (p > mx) {
            se = mx;
            mx = p;
        } else if (p > se) {
            se = p;
        }
    }

    ans = max(ans, mx + se + 1);

    return mx + 1;
}

void solve(){
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

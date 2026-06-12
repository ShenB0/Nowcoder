#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

#define debug(x) cout << #x << " = " << x << endl;
#define lowbit(x) (x) & (-x)
#define ALL(x) (x).begin(), (x).end()

const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double eps = 1e-7;
const int N =  2e5 + 10;

void init(){
    
}

void solve(){
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    vector<int> dsu(n + 1);
    for (int i = 1; i <= n; i++) dsu[i] = i;

    auto find = [&](auto&& find, int x) -> int {
        if (dsu[x] != x) dsu[x] = find(find, dsu[x]);
        return dsu[x];
    };
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        if (x == y) continue;

        x = find(find, x);
        y = find(find, y); 

        if (x == y) {
            cnt++;
        } else {
            dsu[x] = y;
        }
        
        cnt++;
    }

    cout << cnt << "\n";
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();

    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}

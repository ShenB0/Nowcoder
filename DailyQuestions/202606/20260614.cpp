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
    vector<int> a(n);
    map<int, int> mp; 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a.begin(), a.end());
    int ans = min(mp[a[n - m]], m);
    for (int i = n - m - 1; i >= 0; i--) {
        ans = max(min(mp[a[i]], m), ans);
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();

    int t = 1;
    while (t--) solve();
    
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

#define debug(x) cout << #x << " = " << x << endl;
#define lowbit(x) (x) & (-x)
#define vvec vector<vector<int>>
#define rep(i, a, b) for(int i = (a); i <= (int)(b); ++i)

const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double eps = 1e-7;
const int N =  2e5 + 10;

void solve(){
    int n;
    cin >> n;
    
    map<int, vector<int>> X, Y;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        
        X[x].push_back(y);
        Y[y].push_back(x);
    }
    
    int ans = 0;
    for (auto& [v, vec] : X) {
        int sz = vec.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                int d = abs(vec[i] - vec[j]);
                int aim = (vec[i] + vec[j]) / 2;
                if (d % 2 == 0 && Y.count(aim)) {
                    ans += (int)Y[aim].size();
                    if (find(Y[aim].begin(), Y[aim].end(), v) != Y[aim].end()) ans--;
                }
            }
        }
    }
    for (auto& [v, vec] : Y) {
        int sz = vec.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                int d = abs(vec[i] - vec[j]);
                int aim = (vec[i] + vec[j]) / 2;
                if (d % 2 == 0 && X.count(aim)) {
                    ans += (int)X[aim].size();
                    if (find(X[aim].begin(), X[aim].end(), v) != X[aim].end()) ans--;
                }
            }
        }
    }
    
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

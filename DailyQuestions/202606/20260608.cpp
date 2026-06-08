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
const int N =  2e5 + 10;

void solve(){
    map<string, string> mp;
    for (int i = 0; i < 3; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        mp[s2] = s1;
    }
    
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (mp.count(s)) {
            cout << mp[s] << "\n";
        } else {
            cout << "Fake\n";
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

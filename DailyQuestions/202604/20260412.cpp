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
    int pre = 0;
    int ans = 0;
    map<string, int> mp;
    unordered_set<string> st;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
        if (mp[s] > pre && !st.count(s)) {
            pre = mp[s];
            st.insert(s);
            ans++;
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

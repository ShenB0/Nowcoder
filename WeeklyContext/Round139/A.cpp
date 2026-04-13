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
inline bool check(char c){
    return c == 'r' || c == 'e' || c == 'd';
}
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (!check(s[i])) {
            cout << "No\n";
            return ;
        }
    }
    cout << "Yes\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

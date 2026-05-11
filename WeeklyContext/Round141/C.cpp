#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const int INF = 1 << 30;
const int N = 2e5 + 5;
void solve(){
    string s;
    cin >> s;
    int sz = s.size();
    int l = 0, r = sz - 1;
    while (l < r) {
        if (s[l] == s[r]) {
            l++, r--;
        } else if (s[l] == 'm') {
            if (r > 0 && s[r - 1] == 'n' && (r - 1) != l) {
                l++, r -= 2;
            } else {
                cout << "NO\n";
                return ;
            }
        } else if (s[r] == 'm') {
            if (l < (sz - 1) && s[l + 1] == 'n' && (l + 1) != r) {
                l += 2, r--;
            } else {
                cout << "NO\n";
                return ;
            }
        }
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

    

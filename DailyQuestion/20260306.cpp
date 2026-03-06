//STL模拟
//也可以用数组模拟
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
void solve(){
    int m, q;
    cin >> m >> q;
    map<int, int> mp;
    while (q--) {
        int op, num;
        cin >> op >> num;
        int l = num - 3;
        int r = num + 3;
        if (op == 1) {    
            if (l >= 1) mp[l]++;
            if (r <= m) mp[r]++;
        } else {
            if (l >= 1) {
                mp[l]--;
                if (mp[l] == 0) {
                    mp.erase(l);
                }
            }
            if (r <= m) {
                mp[r]--;
                if (mp[r] == 0) {
                    mp.erase(r);
                }
            }
        }
        cout << mp.size() << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}

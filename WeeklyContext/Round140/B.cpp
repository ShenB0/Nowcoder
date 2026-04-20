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
    string s;
    cin >> n >> s;
    stack<int> stk;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'n') {
            stk.push(i);
        } else if (s[i] == 'i') {
            if (stk.empty() || s[stk.top()] != 'n') {
                flag = false;
                break;
            }
            stk.push(i);
        } else if (s[i] == 'u') {
            if (stk.empty() || s[stk.top()] != 'i') {
                flag = false;
                break;
            }
            stk.pop();
            stk.pop();
        } else if (s[i] == 'm') {
            stk.push(i);
        } else if (s[i] == 'o') {
            if (stk.empty() || s[stk.top()] != 'm') {
                flag = false;
                break;
            }
            stk.pop();
        } else {
            flag = false;
            break;
        }
    }
    if (flag) cout << "Yes\n";
    else cout << "No\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

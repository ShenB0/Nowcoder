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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), stk(m + 2), q(m + 2);
    vector<int> st, qu;
    int p1 = -1, p2 = 0, p3 = -1;
    bool is_stk = true, is_q = true;
    for (int i = 0; i < n; i++) cin >> a[i];
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            p1++;
            stk[p1] = x;
            p3++;
            q[p3] = x;
        } else {
            if (p1 >= 0) {
                st.push_back(stk[p1]);
                p1--;
            }
            else {
                is_stk = false;
            }
            if (p2 <= p3) {
                qu.push_back(q[p2]);
                p2++;
            } else {
                is_q = false;
            }
        }
    }
    if (a != st) is_stk = false;
    if (a != qu) is_q = false;
    if (is_stk && is_q) cout << "both\n";
    else if (is_stk) cout << "stack\n";
    else if (is_q) cout << "queue\n";
    else cout << "-1\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}

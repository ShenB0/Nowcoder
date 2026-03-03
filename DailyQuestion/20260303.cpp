#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N = 5e5 + 5;
set<int> st;
void solve(){
    int n;
    cin >> n;
    bool found0 = false;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.insert(x);
        if (!x) {
            found0 = true;
        }
    }
    if (found0) {
        cout << "NO\n";
        return ;
    }
    if (st.size() == 2) {
        auto it = st.begin();
        auto x1 = *it;
        it++;
        auto x2 = *it;
        if (x1 + x2 == 0) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
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
    
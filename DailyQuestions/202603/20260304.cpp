//把x作为左端点，x+h作为右端点，按x排序后，贪心枚举区间，当下一个区间的左端点小于当前区间合并的最大右端点，将区间合并，并更新最大右端点，最后放进multi_set取前m个
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
int h[N];
void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back({x, x + h[i]});
    }
    sort(v.begin(), v.end());
    multiset<int> st;
    for (int i = 0; i < n;) {
        auto [l, r] = v[i];
        int num = 0;
        while(i < n && v[i].first <= r) {
            r = max(r, v[i].second);
            num++;
            i++;
        }
        st.insert(num);
    }
    int ans = n;
    while ((int)st.size() > m) {
        ans -= *st.begin();
        st.erase(st.begin());
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

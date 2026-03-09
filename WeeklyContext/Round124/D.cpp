//滑动窗口+双端队列
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
int a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque<int> q1, q2;//q1:维护最大值;q2:维护最小值 a[q1[0]] ≥ a[q1[1]] ≥ a[q1[2]]
    int l = 0;
    ll ans = 0;
    for (int r = 0; r < n; r++) {
        while (!q1.empty() && a[q1.back()] <= a[r]) {
            q1.pop_back();
        }
        q1.push_back(r);
        while (!q2.empty() && a[q2.back()] >= a[r]) {
            q2.pop_back();
        }
        q2.push_back(r);
        while (a[q1.front()] - a[q2.front()] > 1) {
            l++;
            while (!q1.empty() && q1.front() < l) {
                q1.pop_front();
            }
            while (!q2.empty() && q2.front() < l) {
                q2.pop_front();
            }
        }
        ans += r - l + 1;
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

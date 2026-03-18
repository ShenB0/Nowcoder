//双指针常数更小
#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
const int N = 1e6 + 5;
int a[N];
void solve(){
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int mx = 1, cur = 0;
    queue<int> q;
    int l = a[0] - p, r = a[0] + p;
    for (int i = 0; i < n; i++) {
        q.push(a[i]);
        while  (a[i] > r) {
            cur++;
            l = a[cur] - p;
            r = a[cur] + p;
        }
        while (q.front() < l) {
            q.pop();
        }
        mx = max(mx, (int)q.size());
    }
    cout << mx << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
    

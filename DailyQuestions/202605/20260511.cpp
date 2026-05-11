#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const int INF = 1 << 30;
const int N = 2e5 + 5;
int n, l;
struct cyc{
    double x, y, r;
}a[10];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
double dist(double x1, double x2, double y1, double y2){
    return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
bool check(double x, double y){
    for (int i = 0; i < n; i++) {
        auto [rx, ry, r] = a[i];
        if (dist(rx, x, ry, y) <= r * r) {
            return false;
        }
    }
    return true;
}
void solve(){
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].r;
    }
    set<pair<double, double>> st;
    while (1) {
        double x = uniform_real_distribution<double>(0, l)(rng);
        double y = uniform_real_distribution<double>(0, l)(rng);
        if (!st.count({x, y}) && check(x, y)) {
            cout << x << " " << y << "\n";
            return ;
        } else {
            st.insert({x, y});
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

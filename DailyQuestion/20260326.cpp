//拓扑贪心
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  2e5 + 10;
int deg[N], ans[N];
bool vis[N], use[N];
vector<int> pi[N], box[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int p;
            cin >> p;
            pi[i].push_back(p);
            box[p].push_back(i);
            deg[p]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if ((int)pi[i].size() == 1) {
            q.push(i);
        }
        if (deg[i] == 1) {
            for(int p : box[i]) q.push(p);
        }
    }
    int cnt = 0;
    auto topo = [&]() -> void {
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (vis[u]) continue;
            int P = -1;
            for (auto p : pi[u]) {
                if (use[p]) {
                    continue;
                }
                if (deg[p] == 1) {
                    P = p;
                    break;
                }
                P = p;
            }
            if (P != -1) {
                cnt++;
                ans[u] = P;
                use[P] = vis[u] = true;
                for (auto p : box[P]) {
                    if (vis[p]) continue;
                    int rem = 0;
                    for (auto e : pi[p]) {
                        if (!use[e]) rem++;
                    }
                    if (rem == 1) q.push(p);
                }
                for (auto p : pi[u]) {
                    if (!use[p] && p != P) {
                        deg[p]--;
                        if (deg[p] == 1) {
                            for(auto pos : box[p]) {
                                if(!vis[pos]) q.push(pos);
                            }
                        }
                    }
                }
            }
        }
    };
    topo();
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        q.push(i);
        topo();
    }
    if (cnt < n) {
        cout << "kou is angry\n";
    } else {
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}

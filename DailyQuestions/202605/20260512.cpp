//还可以用(推荐)主席树，或者分治，线段树会超时
#include<bits/stdc++.h>

#define lowbit(x) ((x) & (-x))

using namespace std;
using ll = long long;

const int INF = 1 << 30;
const int N = 1e5 + 5;

struct Node{
    int val, idx;

    bool operator < (const Node& n) const {
        return val < n.val;
    }
}a[N];

struct Query{
    int l, r, k, idx;

    bool operator < (const Query& q) const {
        return k < q.k;
    }
}q[N];

int n, m;
int tree[N << 1], ans[N];

void add(int p, int x){
    while (p <= n) {
        tree[p] += x;
        p += lowbit(p);
    }
}

int query(int p){
    int res = 0;
    while (p > 0) {
        res += tree[p];
        p -= lowbit(p);
    }
    return res;
}

void solve(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
        a[i].idx = i;
    }
    for (int i = 1; i <= m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        q[i] = {l, r, k, i};
    }

    sort(a + 1, a + 1 + n);
    sort(q + 1, q + 1 + m);

    int cur = 1;
    for (int i = 1; i <= m; i++) {
        auto [l, r, k, id] = q[i];

        while (cur <= n && a[cur].val <= k) {
            add(a[cur].idx, 1);
            cur++;
        }
        
        int L = query(l - 1);
        int R = query(r);
        ans[id] = R - L;
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << "\n";
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

    

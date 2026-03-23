#include<bits/stdc++.h>
#define LS p << 1
#define RS (p << 1) | 1
#define MID l + ((r - l) >> 1)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const double eps = 1e-7;
const int N =  1e5 + 10;
struct SegTree{
    ll mx, mi;
}tree[N << 2];
ll tag[N << 2], a[N << 2];
void lazy(int p){
    if (tag[p]) {
        tag[LS] += tag[p];
        tag[RS] += tag[p];
        tree[LS].mx += tag[p];
        tree[RS].mx += tag[p];
        tree[LS].mi += tag[p];
        tree[RS].mi += tag[p];
        tag[p] = 0;
    }
}
void push_up(int p){
    tree[p].mx = max(tree[LS].mx, tree[RS].mx);
    tree[p].mi = min(tree[LS].mi, tree[RS].mi);
}
void build(int p, int l, int r){
    if (l == r) {
        tree[p].mx = a[l];
        tree[p].mi = a[l];
        return ;
    }
    int mid = MID;
    build(LS, l, mid);
    build(RS, mid + 1, r);
    push_up(p);
}
void update(int p, int l, int r, int L, int R, ll k){
    if (L <= l && r <= R) {
        tag[p] += k;
        tree[p].mx += k;
        tree[p].mi += k;
        return ;
    }
    lazy(p);
    int mid = MID;
    if (mid >= L) update(LS, l, mid, L, R, k);
    if (mid < R) update(RS, mid + 1, r, L, R, k);
    push_up(p);
}
int query(int p, int l, int r, int L, int R, ll x){
    if (l > R || r < L) return 0;
    if (L <= l && r <= R) {
        if (tree[p].mx < x) return r - l + 1;
        if (tree[p].mi >= x) return 0;
    }
    if (l == r) return 0;
    lazy(p);
    int mid = MID;
    int res = 0;
    if (mid >= L) res += query(LS, l, mid, L, R, x);
    if (mid < R) res += query(RS, mid + 1, r, L, R, x);
    return res;
}
void solve(){
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--) {
        int op, l, r;
        ll x;
        cin >> op >> l >> r >> x;
        if (op == 1) {
            update(1, 1, n, l, r, x);
        } else {
            cout << query(1, 1, n, l, r, x) << "\n";
        }
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

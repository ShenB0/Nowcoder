//字符串哈希
#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const int N = 1e6 + 5;
const ll INF = 1LL << 60;
const ll BASE = 131;
const ll MOD = 1e9 + 7;
ll hs[N], ht[N], hrs[N], p[N];
//hs[]:记录s的哈希;ht[]:记录t的哈希;hrs[]:记录s反转的哈希;p[]:记录BASE的幂次
ll get(ll h[], ll l, ll r){
    return (h[r] - h[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;
}
void init(){
    p[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = (p[i - 1] * BASE) % MOD;
    }
}
void solve(){
    int n;
    string s, t;
    cin >> n >> s >> t;
    s = " " + s;
    t = " " + t;
    string rs = s;
    reverse(rs.begin() + 1, rs.end());
    hs[0] = ht[0] = hrs[0] = 0;
    int mx = 0, id = 1;
    for (int i = 1; i <= n; i++) {
        hs[i] = (hs[i - 1] * BASE % MOD+ s[i]) % MOD;
        ht[i] = (ht[i - 1] * BASE % MOD+ t[i]) % MOD;
        hrs[i] = (hrs[i - 1] * BASE % MOD + rs[i]) % MOD;
    }
    for (int len = 1; len <= n; len++) {
        int l = 0, r = n;
        int lcp = 0;
        while (l <= r) {
            bool flag = false;
            int mid = l + ((r - l) >> 1);
            if (mid == 0) { 
                l = mid + 1; 
                continue; 
            }
            if (mid <= len) {
                ll hash_rs = get(hrs, n - len + 1, n - len + mid);
                ll hash_t = get(ht, 1, mid);
                if (hash_rs == hash_t) {
                    flag = true;
                }
            } else {
                ll hash_rs = get(hrs, n - len + 1, n);
                ll hash_t = get(ht, 1, len);
                if (hash_rs == hash_t) {
                    ll hash_s = get(hs, len + 1, mid);
                    ll hash_tt = get(ht, len + 1, mid);
                    if (hash_s == hash_tt) {
                        flag = true;
                    }
                }
            }
            if (flag) {
                lcp = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (lcp > mx) {
            mx = lcp;
            id = len;
        }
    }
    cout << mx << " " << id << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    init();
    while (t--) {
        solve();
    }
    return 0;
}

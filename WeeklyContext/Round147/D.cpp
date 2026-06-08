#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

#define debug(x) cout << #x << " = " << x << endl;
#define lowbit(x) (x) & (-x)
#define vec vector<int>
#define vvec vector<vector<int>>
#define rep(i, a, b) for(int i = (a); i <= (int)(b); ++i)

const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double eps = 1e-7;
const int N = 2e5 + 5;
const int MAXN = 1e6 + 10;

int n;

int a[N], pre[N];
int best[MAXN], spf[MAXN], pre_id[MAXN];
vector<int> prime;

void Euler_Sieve_SPF(int n) {
    fill(spf, spf + 1 + n, 0);
    for (int i = 2; i <= n; ++i) {
        if (spf[i] == 0) { 
            spf[i] = i;   
            prime.push_back(i);
        }
        for (int p : prime) {
            if (i * p > n) break;
            spf[i * p] = p; 
            if (i % p == 0) break; 
        }
    }
}

void solve(){
    memset(best, 0, sizeof(best));
    memset(pre, -1, sizeof(pre));
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int mx = 0, pos = -1;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cur = 1, last = -1;
        while (x > 1) {
            int p = spf[x];
            int prev = a[i] / p;
            if (best[prev] > 0 && (best[prev] + 1) > cur) {
                cur = best[prev] + 1;
                last = pre_id[prev];
            }
            while (x % p == 0) x /= p;
        } 
        
        pre_id[a[i]] = i; 
        pre[i] = last;
        
        if (cur >= best[a[i]]) {
            best[a[i]] = cur;
        }
        
        if (cur > mx) {
            mx = cur;
            pos = i;
        }
    }
    
    cout << mx << "\n";
    stack<int> stk;
    while (~pos) {
        stk.push(pos);
        pos = pre[pos];
    }
    while (!stk.empty()) {
        cout << a[stk.top()] << " ";
        stk.pop();
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Euler_Sieve_SPF(MAXN - 10);
    
    int t = 1;
    while (t--) solve();
    
    return 0;
}

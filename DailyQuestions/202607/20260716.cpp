#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

#define debug(x) cout << #x << " = " << x << endl;
#define lowbit(x) (x) & (-x)
#define ALL(x) (x).begin(), (x).end()

const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double eps = 1e-7;
const int N = 2e5 + 10;

void init(){
    
}

void solve(){
    int n;
    string s;
    cin >> s >> n;
    
    int m = s.size();
    vector<int> nxt(m + 1, 0);
    
    auto kmp = [&]() -> void {
        for (int i = 1; i < m; i++) {
            int j = nxt[i];
            while (j > 0 && s[i] != s[j]) {
                j = nxt[j];
            }
            if (s[i] == s[j]) {
                j++;
            }
            nxt[i + 1] = j;
        }
    };

    kmp();

    int tot = 0;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;

        int ptr = 0;
        int mx = 0;
        int sz = t.size();
        for (int j = 0; j < sz; j++) {
            if (ptr >= m) {
                mx = m;
                break;
            }

            while (ptr > 0 && t[j] != s[ptr]) {
                ptr = nxt[ptr];
            }
            if (t[j] == s[ptr]) {
                ptr++;
            }

            mx = max(mx, ptr);
        }

        tot += mx;
    }

    cout << tot << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();

    int t = 1;
    while (t--) solve();
    
    return 0;
}

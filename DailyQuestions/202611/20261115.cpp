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
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt1 = 0;
    vector<int> R(n, 0), C(m, 0);

    int allone_r_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            R[i] += a[i][j] - '0';
        }
        cnt1 += R[i];
        allone_r_cnt += (R[i] == m) ? 1 : 0;
    }

    int allone_c_cnt = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            C[j] += a[i][j] - '0';
        }
        allone_c_cnt += (C[j] == n) ? 1 : 0;
    }

    // debug(cnt1);

    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // debug(R[i] + C[i]);
            if (R[i] + C[j] == cnt1 && cnt1 == n + m - 2 && a[i][j] == '0') {
                flag = true;
                break;
            }
        }
    }

    if (cnt1 == 0) {
        cout << "YES\n";
        return ;
    } else if (flag) {
        cout << "YES\n";
        return ;
    } else {
        if (allone_r_cnt == 2 && cnt1 == 2 * m || allone_c_cnt == 2 && cnt1 == 2 * n) {
            cout << "YES\n";
            return ;
        }
    }
    cout << "NO\n";
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();

    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}

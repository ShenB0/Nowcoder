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
const int N =  1e3 + 10;

string a[5];

void solve(){
    int n, h;
    cin >> n >> h;
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[1][i] == '*') {
            c1++;
            if (a[0][i] == '*') {
                c1++;
            }
        } else {
            if (a[0][i] == '*') {
                c2++;
            }
        }
        if (a[3][i] == '*') {
            c1++;
            if (a[4][i] == '*') {
                c1++;
            }
        } else {
            if (a[4][i] == '*') {
                c2++;
            }
        }
    }

    if (h <= c1) {
        cout << h << "\n";
    } else {
        cout << c1 + min(c2, (h - c1) / 2) << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) solve();
    
    return 0;
}

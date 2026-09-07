#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 10;
const int INF = 1 << 30;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (a[1] != 0 && a[n] != 0 && a[1] == a[n]) {
        cout << "-1\n";
        return ;
    }

    int l = -1, r = -1, k = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != 0) {
            if (l == -1) {
                l = a[i];
                continue;
            }

            if (a[i] == l) {
                if (r == -1) {
                    continue;
                } else {
                    cout << "-1\n";
                    return ;
                }
            }

            if (r == -1) {
                k = i;
                r = a[i];
                continue;
            } 
            
            if (a[i] != r) {
                cout << "-1\n";
                return ;
            }
        }
    }

    if (l == -1) {
        for (int i = 1; i < n; i++) {
            cout << "1 ";
        }
        cout << "2\n";
        return ;
    }

    if (r == -1) {
        if (a[n] == 0) {
            a[n] = (l == (int)1e9 ? l - 1 : l + 1);
        } else {
            a[1] = (l == (int)1e9 ? l - 1 : l + 1);
        }

        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                a[i] = l;
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        return ;
    }

    if (abs(l - r) > 1) {
        cout << "-1\n";
        return ;
    }

    for (int i = k - 1; i >= 1; i--) {
        if (a[i] == 0) a[i] = l;
    }
    for (int i = k + 1; i <= n; i++) {
        if (a[i] == 0) a[i] = r;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}

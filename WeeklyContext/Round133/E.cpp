#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        cout << "-1\n";
        return;
    }
    bool rev = false;
    if (y1 > y2) {
        y1 = n - y1 + 1;
        y2 = n - y2 + 1;
        rev = true;
    }
    string ans;
    ans.reserve(2 * n + 5); 
    if (y1 == y2) {
        if (y1 == 1) {
            ans.append(n - 1, 'R');
            ans.push_back(x1 == 1 ? 'D' : 'U');
            ans.append(n - 1, 'L');
        } else if (y1 == n) {
            ans.append(n - 1, 'L');
            ans.push_back(x1 == 1 ? 'D' : 'U');
            ans.append(n - 1, 'R');
        } else {
            cout << "-1\n";
            return;
        }
    } 
    else {
        int cx = x1;
        int cy = y1;
        if (y1 > 1) {
            ans.append(y1 - 1, 'L');
            ans.push_back(cx == 1 ? 'D' : 'U');
            cx = 3 - cx;
            ans.append(y1 - 1, 'R');
        } else {
            ans.push_back(cx == 1 ? 'D' : 'U');
            cx = 3 - cx;
        }
        while (cy < y2) {
            ans.push_back('R'); 
            cy++;
            if (cy == y2) break; 
            ans.push_back(cx == 1 ? 'D' : 'U'); 
            cx = 3 - cx;
        }
        ans.append(n - y2, 'R');
        ans.push_back(cx == 1 ? 'D' : 'U'); 
        cx = 3 - cx;
        ans.append(n - y2, 'L');
    }
    if (rev) {
        for (char &c : ans) {
            if (c == 'L') c = 'R';
            else if (c == 'R') c = 'L';
        }
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    while (t--) solve();
    return 0;
}

#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while (q--) {
        int l, r;
        cin >> l >> r;
        int L = lower_bound(a.begin(), a.end(), l) - a.begin();
        int R = upper_bound(a.begin(), a.end(), r) - a.begin();
        cout << R - L << "\n";
    }
}

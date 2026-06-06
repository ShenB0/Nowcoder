#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    string s;
    cin >> n >> s;

    if (s[n - 1] == '0') {
        cout << "-1\n";
        return 0;
    }

    int l = 0;
    vector<int> a(n);
    for (int r = 0; r < n; r++) {
        if (s[r] == '1') {
            int v = r + 1;
            while (l <= r) {
                a[l] = v;
                v--;
                l++;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}

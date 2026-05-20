#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const string a[] = {"", "2", "3", "5", "5", "7", "7", "11", "11", "11"};
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int sz = s.size();
        string ans = string(sz - 1, '0');
        ans = a[s[0] - '0'] + ans;
        cout << ans << "\n";
    }
}
// 64 位输出请用 printf("%lld")

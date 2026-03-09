#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += s[i] - '0';
    }
    if (cnt == 0) {
        cout << "0\n";
    } else if (cnt == n) {
        cout << n << "\n";
    } else {
        cout << n - 1 << "\n";
    }
}
int main(){
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

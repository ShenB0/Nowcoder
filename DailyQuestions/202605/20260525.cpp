#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
int a[N];

int main() {
    int n;
    ll k;
    cin >> n >> k;
    k *= 100;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;

    priority_queue<ll, vector<ll>, greater<>> q;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            q.push(a[i] * 95);
        } else {
            q.push(a[i] * 100);
        }
    }
    int cur = 0;
    while (!q.empty() && k > 0) {
        auto x = q.top();
        q.pop();
        if (k >= x) {
            k -= x;
            cur++;
        } else {
            break;
        }
    }
    cout << cur << "\n";
}
// 64 位输出请用 printf("%lld")

#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int main() {
    int n;
    cin >> n;
    int cur = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                cur += i;
                n /= i;
            }
        }
    }
    if (n > 1) {
        cur += n;
    } 
    cout << cur << "\n";
}
// 64 位输出请用 printf("%lld")
